#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificación de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificación de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	Shader OurShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers
	//VAO
	float vertices[] = {
		//Casa
		-0.85f, 0.10f, 0.0f,    1.0f, 0.0f, 0.0f,  // A rojo
		-0.15f, 0.10f, 0.0f,    1.0f, 0.0f, 0.0f,  // B rojo
		-0.50f, 0.45f, 0.0f,    1.0f, 0.0f, 0.0f,  // C rojo
		-0.85f, 0.10f, 0.0f,    1.0f, 0.5f, 0.0f,  // A naranja
		-0.85f, 0.45f, 0.0f,    1.0f, 0.5f, 0.0f,  // F naranja
		-0.50f, 0.45f, 0.0f,    1.0f, 0.5f, 0.0f,  // C naranja
		-0.15f, 0.10f, 0.0f,    1.0f, 0.0f, 1.0f,  // B magenta
		-0.33f, 0.28f, 0.0f,    1.0f, 0.0f, 1.0f,  // E magenta
		-0.15f, 0.45f, 0.0f,    1.0f, 0.0f, 1.0f,  // D magenta
		-0.5f,  0.45f, 0.0f,    0.0f, 0.5f, 1.0f,  // C azul
		-0.33f, 0.28f, 0.0f,    0.0f, 0.5f, 1.0f,  // E azul
		-0.15f, 0.45f, 0.0f,    0.0f, 0.5f, 1.0f,  // D azul
		-0.75f, 0.45f, 0.0f,    1.0f, 1.0f, 0.0f,  // G amarillo
		-0.05f, 0.45f, 0.0f,    1.0f, 1.0f, 0.0f,  // H amarillo
		-0.40f, 0.80f, 0.0f,    1.0f, 1.0f, 0.0f,  // I amarillo
		-0.50f, 0.70f, 0.0f,    0.5f, 0.0f, 1.0f,  // J morado
		-0.75f, 0.45f, 0.0f,    0.5f, 0.0f, 1.0f,  // G morado
		-0.70f, 0.70f, 0.0f,    0.5f, 0.0f, 1.0f,  // N morado
		-0.95f, 0.45f, 0.0f,    0.5f, 0.0f, 1.0f,  // K morado
		-0.50f, 0.70f, 0.0f,    0.0f, 1.0f, 0.0f,  // J verde
		-0.70f, 0.70f, 0.0f,    0.0f, 1.0f, 0.0f,  // N verde
		-0.50f, 0.90f, 0.0f,    0.0f, 1.0f, 0.0f,  // L verde
		-0.70f, 0.90f, 0.0f,    0.0f, 1.0f, 0.0f,  // M verde
		
		//Gato
		0.10f, -0.10f, 0.0f,    1.0f, 0.0f, 1.0f,  // O magenta
		0.10f, -0.30f, 0.0f,    1.0f, 0.0f, 1.0f,  // P magenta
		0.20f, -0.20f, 0.0f,    1.0f, 0.0f, 1.0f,  // Q magenta
		0.30f, -0.10f, 0.0f,    0.0f, 0.5f, 1.0f,  // R azul
		0.30f, -0.30f, 0.0f,    0.0f, 0.5f, 1.0f,  // S azul
		0.20f, -0.20f, 0.0f,    0.0f, 0.5f, 1.0f,  // Q azul
		0.20f, -0.20f, 0.0f,    0.0f, 1.0f, 0.0f,  // Q verde
		0.10f, -0.30f, 0.0f,    0.0f, 1.0f, 0.0f,  // P verde
		0.30f, -0.30f, 0.0f,    0.0f, 1.0f, 0.0f,  // S verde
		0.20f, -0.40f, 0.0f,    0.0f, 1.0f, 0.0f,  // T verde
		0.20f, -0.40f, 0.0f,    0.5f, 0.0f, 1.0f,  // T morado
		0.35f, -0.25f, 0.0f,    0.5f, 0.0f, 1.0f,  // U morado
		0.35f, -0.40f, 0.0f,    0.5f, 0.0f, 1.0f,  // V morado
		0.50f, -0.25f, 0.0f,    0.5f, 0.0f, 1.0f,  // W morado
		0.35f, -0.40f, 0.0f,    1.0f, 0.5f, 0.0f,  // V naranja
		0.50f, -0.25f, 0.0f,    1.0f, 0.5f, 0.0f,  // W naranja
		0.50f, -0.55f, 0.0f,    1.0f, 0.5f, 0.0f,  // X naranja
		0.50f, -0.25f, 0.0f,    1.0f, 1.0f, 0.0f,  // W amarillo
		0.50f, -0.75f, 0.0f,    1.0f, 1.0f, 0.0f,  // Y amarillo
		0.75f, -0.50f, 0.0f,    1.0f, 1.0f, 0.0f,  // Z amarillo
		0.75f, -0.50f, 0.0f,    1.0f, 0.0f, 0.0f,  // Z rojo
		0.40f, -0.85f, 0.0f,    1.0f, 0.0f, 0.0f,  // A1 rojo
		0.75f, -0.85f, 0.0f,    1.0f, 0.0f, 0.0f,  // B1 rojo


	};

	//EBO
	unsigned int indices[] = {  // note that we start from 0!
		//Casa
		0,1,2,
		3,4,5,
		6,7,8,
		9,10,11,
		12,13,14,
		15,16,17,18,
		19,20,21,22,
		//Gato
		23,24,25,
		26,27,28,
		29,30,31,32,
		33,34,35,36,
		37,38,39,
		40,41,42,
		43,44,45
		
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Desenlazamos de memoria el VAO


	
	while (!glfwWindowShouldClose(window))
	{
		// Checa si un eveneto ha sido activado y manda a llamar al callback correspondiente
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Dibujar aquí
		OurShader.Use();
		glBindVertexArray(VAO);
		glPointSize(10);
		//Casa
	    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(0 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(3 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(6 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(9 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(12 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(15 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(16 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(19 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(20 * sizeof(GLfloat)));
		//Gato
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(23 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(26 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(29 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(30 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(33 * sizeof(GLfloat))); 
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(34 * sizeof(GLfloat))); 
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(37 * sizeof(GLfloat))); 
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(40 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(43 * sizeof(GLfloat)));



		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}