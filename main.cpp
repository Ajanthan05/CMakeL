#include <iostream>
using namespace std;

// Add hedder
//#include <Adder/adder.h>	//float add(float a, float b);
//target_include_diredtories(${PROJECT_NAME} PUBLI Adder) // after
#include <adder.h>

#include <GLFW/glfw3.h>

int main()
{
	// prints hello world
	cout << "Hello World\n";
	cout<< add(9.5f, 7.2f) <<endl;

	GLFWwindow* window;

	if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
	window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
	while( !glfwWindowShouldClose(window) )
    {
        // Draw gears
        //draw();

        // Update animation
        //animate();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

	return 0;
}
