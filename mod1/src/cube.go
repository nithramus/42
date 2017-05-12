// Copyright 2014 The go-gl Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// Renders a textured spinning cube using GLFW 3 and OpenGL 2.1.
package main

import (
	"log"
	"runtime"

	"github.com/go-gl/gl/v2.1/gl"
	"github.com/go-gl/glfw/v3.2/glfw"
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

func draw(surface *[width][height]float32) {
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
	rotationX = 120
	rotationY = 360
	rotationZ = 0

	setupScene()
	for !window.ShouldClose() {
		drawScene(surface)
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

func drawScene(surface *[width][height]float32) {
	gl.Clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT)

	var i float32 = 0
	var j float32 = 0
	var k int
	var t int
	gl.MatrixMode(gl.MODELVIEW)
	gl.LoadIdentity()
	gl.Translatef(-1, -1, -3)
	gl.Rotatef(rotationX, 1, 0, 0)
	gl.Rotatef(rotationY, 0, 1, 0)
	gl.Rotatef(rotationZ, 0, 0, 1)

	rotationX -= 0.5
	rotationY -= 0.5
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
					if surface[k][t] != 0 {
						gl.Color3ub(200, uint8(surface[k][t]), uint8(surface[k][t]))
					}
					t++
				}
				k++
			}
			gl.Vertex3f(i*2/width, j*2/height, -surface[int(i)][int(j)]/200)
			gl.Vertex3f((i+1)*2/width, j*2/height, -surface[int(i+1)][int(j)]/200)
			gl.Vertex3f(i*2/width, (j+1)*2/height, -surface[int(i)][int(j+1)]/200)
			gl.Vertex3f((i+1)*2/width, j*2/height, -surface[int(i+1)][int(j)]/200)
			gl.Vertex3f(i*2/width, (j+1)*2/height, -surface[int(i)][int(j+1)]/200)
			gl.Vertex3f((i+1)*2/width, (j+1)*2/height, -surface[int(i+1)][int(j+1)]/200)
			j += 1
		}
		i += 1
	}
	gl.End()
}
