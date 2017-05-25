package main

import (
	"fmt"
	"github.com/go-gl/gl/v2.1/gl"
	"github.com/go-gl/glfw/v3.2/glfw"
	"log"
	"runtime"
)

var (
	texture   uint32
	rotationX float32
	rotationY float32
	rotationZ float32
)

func init() {
	// GLFW event handling must run on the main OS thread
	runtime.LockOSThread()
}

func draw(surface *[width][height]float64, water *[width][height]block) {
	if err := glfw.Init(); err != nil {
		log.Fatalln("failed to initialize glfw:", err)
	}
	defer glfw.Terminate()

	glfw.WindowHint(glfw.Resizable, glfw.False)
	glfw.WindowHint(glfw.ContextVersionMajor, 2)
	glfw.WindowHint(glfw.ContextVersionMinor, 1)
	window, err := glfw.CreateWindow(800, 600, "Cube", nil, nil)
	if err != nil {
		panic(err)
	}
	window.MakeContextCurrent()

	if err := gl.Init(); err != nil {
		panic(err)
	}
	rotationX = 100
	rotationY = 360
	rotationZ = 30

	setupScene()
	var hauteur float64
	drawScene(surface)
	go showme("yolo")
	go showme("yorfegty")
	for !window.ShouldClose() {
		hauteur += 1
		water_gen(3, water, surface, hauteur)
		drawScene(surface)
		draw_water(surface, water)
		window.SwapBuffers()
		glfw.PollEvents()
	}
}

func setupScene() {
	gl.Enable(gl.DEPTH_TEST)

	gl.ClearColor(0, 0, 0, 0.0)
	gl.ClearDepth(1)
	gl.DepthFunc(gl.LEQUAL)

	gl.MatrixMode(gl.PROJECTION)
	gl.LoadIdentity()
	gl.Frustum(-1, 1, -1, 1, 1.0, 10.0)
	gl.MatrixMode(gl.MODELVIEW)
	gl.LoadIdentity()
}

func destroyScene() {
}

func showme(tst string) {
	i := 0
	for i = 0; i < 40000; i++ {
	}
	fmt.Println(tst, i)
}

func draw_water(surface *[width][height]float64, water *[width][height]block) {

	var ifloat float32
	var ifloatone float32
	var jfloat float32
	var jfloatone float32
	var kfloat float64

	/*	gl.MatrixMode(gl.MODELVIEW)
		gl.LoadIdentity()
		gl.Translatef(-1, -1, -4)
		gl.Rotatef(rotationX, 1, 0, 0)
		gl.Rotatef(rotationY, 0, 1, 0)
		gl.Rotatef(rotationZ, 0, 0, 1)
	*/
	gl.Color3ub(0, 0, 200)
	gl.Begin(gl.QUADS)

	for i := range water {
		ifloat = float32(float64(i*2) / float64(width))
		ifloatone = float32(float64(i+1) * 2 / float64(width))
		for j := range water[i] {
			jfloat = float32(float64(j*2) / float64(height))
			jfloatone = float32(float32(j+1) * 2 / float32(height))
			if water[i][j].block != 0 { //&& water[i][j].todraw == 1 {
				water[i][j].todraw = 0
				kfloat = float64(water[i][j].block)
				//			fmt.Println(water[i][j].block, surface[i][j])

				gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j]+kfloat)/200))
				gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j]+kfloat)/200))
				gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j]+kfloat)/200))
				gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j]+kfloat)/200))

				gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j]+kfloat+1)/200))

				gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j]+kfloat)/200))
				gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j]+kfloat)/200))

				gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j]+kfloat)/200))
				gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j]+kfloat)/200))

				gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j]+kfloat)/200))
				gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j]+kfloat)/200))

				gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j]+kfloat)/200))
				gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j]+kfloat+1)/200))
				gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j]+kfloat)/200))

			}
		}
	}
	gl.End()
}

func drawScene(surface *[width][height]float64) {

	var i float64 = 0
	var j float64 = 0
	var k int
	var t int
	var inorm float32
	var iplusone float32
	var jnorm float32
	var jplusone float32

	gl.Clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT)
	gl.MatrixMode(gl.MODELVIEW)
	gl.LoadIdentity()
	gl.Translatef(0, -1, -4)
	gl.Rotatef(rotationX, 1, 0, 0)
	gl.Rotatef(rotationY, 0, 1, 0)
	gl.Rotatef(rotationZ, 0, 0, 1)

	/*rotationX -= 0.5
	rotationY -= 0.5*/
	gl.Begin(gl.TRIANGLES)

	gl.Color3ub(200, 0, 0)
	for i < width-1 {
		j = 0
		gl.Color3ub(200, 0, 0)
		for j < height-1 {
			k = int(i)
			for k < int(i)+2 {
				t = int(j)
				for t < int(j)+2 {
					if surface[k][t] > 40 {
						gl.Color3ub(20+uint8(surface[k][t]), uint8(surface[k][t]), uint8(surface[k][t]))
					} else {
						gl.Color3ub(20+uint8(surface[k][t]), 30+uint8(surface[k][t]), 0)
					}
					t++
				}
				k++
			}
			inorm = float32(i * 2 / width)
			iplusone = float32((i + 1) * 2 / width)
			jnorm = float32(j * 2 / width)
			jplusone = float32((j + 1) * 2 / width)

			gl.Vertex3f(inorm, jnorm, float32(-surface[int(i)][int(j)]/200))
			gl.Vertex3f(iplusone, jnorm, float32(-surface[int(i+1)][int(j)]/200))
			gl.Vertex3f(inorm, jplusone, float32(-surface[int(i)][int(j+1)]/200))
			gl.Vertex3f(iplusone, jnorm, float32(-surface[int(i+1)][int(j)]/200))
			gl.Vertex3f(inorm, jplusone, float32(-surface[int(i)][int(j+1)]/200))
			gl.Vertex3f(iplusone, jplusone, float32(-surface[int(i+1)][int(j+1)]/200))
			j += 1
		}
		i += 1
	}
	gl.End()
}
