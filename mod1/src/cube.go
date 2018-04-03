package main

import (
	"fmt"
	"log"
	"runtime"
	"time"

	"github.com/go-gl/gl/v2.1/gl"
	"github.com/go-gl/glfw/v3.2/glfw"
)

var (
	texture   uint32
	rotationX float32
	rotationY float32
	rotationZ float32
	zoom      float32
)

func init() {
	// GLFW event handling must run on the main OS thread
	fmt.Println("initied")
	runtime.LockOSThread()
}

func draw(surface *[width][height]float64, water *[width][height]float64, mode int, tours int) {
	if err := glfw.Init(); err != nil {
		log.Fatalln("failed to initialize glfw:", err)
	}
	defer glfw.Terminate()

	glfw.WindowHint(glfw.Resizable, glfw.False)
	glfw.WindowHint(glfw.ContextVersionMajor, 2)
	glfw.WindowHint(glfw.ContextVersionMinor, 1)
	window, err := glfw.CreateWindow(1200, 900, "Cube", nil, nil)
	if err != nil {
		panic(err)
	}
	window.MakeContextCurrent()

	if err := gl.Init(); err != nil {
		panic(err)
	}
	rotationX = 110
	rotationY = 370
	rotationZ = 30
	zoom = -2.5

	setupScene()
	var hauteur int
	drawScene(surface)
	lastTime := time.Now()
	// test_water(water)
	// window.SetInputMode(glfw.StickyKeysMode, 1)
	for !window.ShouldClose() {
		if time.Since(lastTime) > 5000000 {
			lastTime = time.Now()
			water_gen(mode, water, surface, hauteur, tours)
			glfw.PollEvents()
			goZoom := window.GetKey(glfw.KeyA)
			goDeZoom := window.GetKey(glfw.KeyZ)
			goLeft := window.GetKey(glfw.KeyLeft)
			goRight := window.GetKey(glfw.KeyRight)
			goUp := window.GetKey(glfw.KeyUp)
			goDown := window.GetKey(glfw.KeyDown)

			if (hauteur%2 == 0 && mode == 2) || (hauteur%1 == 0 && mode == 3 || (mode == 1 && hauteur%1 == 0)) {
				if goLeft == 1 {
					rotationZ += 3
				}
				if goRight == 1 {
					rotationZ -= 3
				}
				if goUp == 1 {
					rotationX -= 3
				}
				if goDown == 1 {
					rotationX += 3
				}
				if goZoom == 1 {
					zoom += 0.1
				}
				if goDeZoom == 1 {
					zoom -= 0.1
				}
				drawScene(surface)
				draw_water(surface, water, mode)
				window.SwapBuffers()
				print(hauteur, "\n")
			}
			hauteur += 1
		}
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
}

func draw_water(surface *[width][height]float64, water *[width][height]float64, mode int) {

	var ifloat float32
	var ifloatone float32
	var jfloat float32
	var jfloatone float32
	var kfloat float64

	gl.MatrixMode(gl.MODELVIEW)
	gl.LoadIdentity()
	gl.Translatef(0, -1, zoom)
	gl.Rotatef(rotationX, 1, 0, 0)
	gl.Rotatef(rotationY, 0, 1, 0)
	gl.Rotatef(rotationZ, 0, 0, 1)

	gl.Color3ub(0, 0, 200)
	gl.Begin(gl.QUADS)

	for i := range water {
		if float64(i) != width-1 && i != 0 {
			ifloat = float32(float64(i*2)/float64(width)) - 1
			ifloatone = float32(float64(i+1)*2/float64(width)) - 1
			for j := range water[i] {
				if float64(j) != height-1 && j != 0 {
					jfloat = float32(float64(j*2)/float64(height)) - 1
					jfloatone = float32(float32(j+1)*2/float32(height)) - 1
					if water[i][j] >= 0.1 {
						gl.Color3ub(30, 100, 200-((uint8(water[i][j]))*2))
						kfloat = float64(water[i][j])
						draw_square_water(surface, water, kfloat, i, j, ifloat, jfloat, jfloatone, ifloatone)
					}
				}
			}
		}
	}
	gl.End()
}

func draw_square_water(surface *[width][height]float64, water *[width][height]float64, kfloat float64, i int, j int, ifloat float32, jfloat float32, jfloatone float32, ifloatone float32) {

	gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j]+kfloat)/200))
	gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j]+kfloat)/200))
	gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j]+kfloat)/200))
	gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j]+kfloat)/200))

	// bas
	gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j])/200))
	// cote
	gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j]+kfloat)/200))
	gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j]+kfloat)/200))

	gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j]+kfloat)/200))
	gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j]+kfloat)/200))

	gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j]+kfloat)/200))
	gl.Vertex3f(ifloat, jfloat, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloatone, jfloat, float32(-(surface[i][j]+kfloat)/200))
	// fin du coté

	gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j]+kfloat)/200))
	gl.Vertex3f(ifloat, jfloatone, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j])/200))
	gl.Vertex3f(ifloatone, jfloatone, float32(-(surface[i][j]+kfloat)/200))

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
	gl.Translatef(0, -1, zoom)
	gl.Rotatef(rotationX, 1, 0, 0)
	gl.Rotatef(rotationY, 0, 1, 0)
	gl.Rotatef(rotationZ, 0, 0, 1)

	gl.Begin(gl.TRIANGLES)

	gl.Color3ub(200, 0, 0)
	for i < width-1 {
		j = 0
		k = int(i)
		gl.Color3ub(200, 0, 0)
		for j < height-1 {
			t = int(j)
			if surface[k][t] > 20 {
				gl.Color3ub(uint8(surface[k][t]), uint8(surface[k][t]), uint8(surface[k][t]))
			} else if surface[k][t] < 20 && surface[k][t] > 0 {
				gl.Color3ub(uint8(surface[k][t]), uint8(surface[k][t])+30, uint8(surface[k][t]))
			} else {
				gl.Color3ub(20+uint8(surface[k][t]), uint8(surface[k][t]), uint8(surface[k][t]))
			}
			inorm = float32(i*2/width) - 1
			iplusone = float32((i+1)*2/width) - 1
			jnorm = float32(j*2/width) - 1
			jplusone = float32((j+1)*2/width) - 1

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
