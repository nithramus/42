#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <unistd.h>
#include "libft/libft/libft.h"


char *LoadSource(const char *filename);

GLuint	shader_creation()
{
	GLuint shader;
	char *src;
	const char **string;
	GLint compile_ok = GL_TRUE;
	int logsize = 0;
	char *log;

	shader = glCreateShader(GL_FRAGMENT_SHADER);

	src = LoadSource("shader.fragmentshader");
	if (!src)
		ft_putendl("src non chargee");
	string = (const char**)&src;
	glShaderSource(shader, 1, string, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_ok);
	if (compile_ok != GL_TRUE)
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logsize);
		printf("%d\n", compile_ok);
		log = malloc(logsize);
		glGetShaderInfoLog(shader, logsize, &logsize, log);
		log[logsize] = '\0';
	ft_putendl("erreur:");
		ft_putendl(log);
	}


	GLuint fragshader;
	fragshader = glCreateShader(GL_VERTEX_SHADER);

	src = LoadSource("vertex.vertexshader");
	if (!src)
		ft_putendl("src non chargee");
	string = (const char**)&src;
	glShaderSource(fragshader, 1, string, NULL);
	glCompileShader(fragshader);
	glGetShaderiv(fragshader, GL_COMPILE_STATUS, &compile_ok);
	if (compile_ok != GL_TRUE)
	{
		glGetShaderiv(fragshader, GL_INFO_LOG_LENGTH, &logsize);
		printf("%d\n", compile_ok);
		log = malloc(logsize);
		glGetShaderInfoLog(shader, logsize, &logsize, log);
		log[logsize] = '\0';
	ft_putendl("erreur2:");
		ft_putendl(log);
	}




	compile_ok = GL_TRUE;
	GLuint program = glCreateProgram();
	glAttachShader(program ,shader);
	glAttachShader(program ,fragshader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &compile_ok);
	if (compile_ok != GL_TRUE)
	{
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logsize);
		printf("%d\n", compile_ok);
		log = malloc(logsize);
		glGetProgramInfoLog(program, logsize, &logsize, log);
		log[logsize] = '\0';
		ft_putendl("erreur:");
		ft_putendl(log);
		ft_putendl("Erreur au linkage");
	}

	glDeleteShader(shader);
	return (program);
}

int main()
{
	SDL_Window *fenetre;
	SDL_Event event;
	SDL_GLContext contexteOpenGL;
	static const GLfloat vertices[] = {-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f};

	glewExperimental=GL_TRUE;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	fenetre = SDL_CreateWindow("openglinc",  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	contexteOpenGL = SDL_GL_CreateContext(fenetre);
	SDL_GL_MakeCurrent(fenetre, contexteOpenGL);
	if (glewInit() != GLEW_OK)
	{
		write(1, "err", 3);
		return (0);
	}
	glClearColor(0.0f,0.0f,0.4f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	GLuint vertexbuffer;

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(vertices), vertices, GL_STATIC_DRAW);



	GLuint program = shader_creation();
	glUseProgram(program);

	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	if(glGetError() != GL_NO_ERROR)
		ft_putendl("nique sa maman0");

	while (1)
	{

	if(glGetError() != GL_NO_ERROR)
		ft_putendl("nique sa maman3");

	glEnableVertexAttribArray(0);
	if(glGetError() != GL_NO_ERROR)
		ft_putendl("nique sa maman1");
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	if(glGetError() != GL_NO_ERROR)
		ft_putendl("nique sa maman2");


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
	if(glGetError() != GL_NO_ERROR)
		ft_putendl("nique sa maman4");
	glDrawArrays(GL_TRIANGLES, 0, 3);
	if(glGetError() != GL_NO_ERROR)
		ft_putendl("nique sa maman5");
	glDisableVertexAttribArray(0);
	glFlush();
	SDL_GL_SwapWindow(fenetre);
/*
glMatrixMode(GL_MODELVIEW);
gluLookAt(3,2,3,0,0,0,0,1,0); 
glColor3f(0.0f,0.0f,1.0f); //blue color
    
    glPointSize(10.0f);//set point size to 10 pixels
glBegin(GL_LINES);
  glVertex2i(0,0);glVertex2i(0,1);
  glVertex2i(0,0);glVertex2i(1,0);
  glVertex2i(0,0);glVertex3i(0,0,1);
glEnd();
	SDL_GL_SwapWindow(fenetre);
*/

	SDL_PollEvent(&event);
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			break;
	}
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return(0);
}
