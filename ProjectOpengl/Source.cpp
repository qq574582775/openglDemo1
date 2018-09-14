#include <iostream>  
#include <glad/glad.h>
#include <GLFW/glfw3.h>


/*********************************DEMO 3
��OpenGL�У��κ����ﶼ��3D�ռ��У�����Ļ�ʹ���ȴ��2D�������飬�⵼��OpenGL�Ĵ󲿷ֹ������ǹ��ڰ�3D����ת��Ϊ��Ӧ����Ļ��2D���ء�3D����תΪ2D����Ĵ����������OpenGL��ͼ����Ⱦ���ߣ�Graphics Pipeline�������Ϊ���ߣ�ʵ����ָ����һ��ԭʼͼ������;��һ�����͹ܵ����ڼ侭�����ֱ仯�������ճ�������Ļ�Ĺ��̣�����ġ�ͼ����Ⱦ���߿��Ա�����Ϊ������Ҫ���֣���һ���ְ����3D����ת��Ϊ2D���꣬�ڶ������ǰ�2D����ת��Ϊʵ�ʵ�����ɫ�����ء�����̳�����ǻ�򵥵�����һ��ͼ����Ⱦ���ߣ��Լ��������������һЩƯ�������ء�*/

//https://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/

int main()
{
    return 0;
}




/************************* DEMO 2
//���û��ı䴰�ڵĴ�С��ʱ���ӿ�ҲӦ�ñ��������ص�
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main()
{
    glfwInit();
    //���ǽ����汾��(Major)��Ϊ3�ʹΰ汾��(Minor)����Ϊ3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //����GLFW����ʹ�õ��Ǻ���ģʽ(Core-profile)��
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //���ʹ�õ���Mac OS Xϵͳ���㻹��Ҫ���������д��뵽��ĳ�ʼ����������Щ���ò��������ã�������Ĵ�����ע�ͣ���
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    GLFWwindow* window = glfwCreateWindow(400, 300, "First OpenGL window", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //���Ǹ�GLAD��������������ϵͳ��ص�OpenGL����ָ���ַ�ĺ�����GLFW�����ǵ���glfwGetProcAddress�����������Ǳ����ϵͳ��������ȷ�ĺ�����
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //�����ǿ�ʼ��Ⱦ֮ǰ����һ����Ҫ������Ҫ�������Ǳ������OpenGL��Ⱦ���ڵĳߴ��С�����ӿ�(Viewport)������OpenGL��ֻ��֪���������ݴ��ڴ�С��ʾ���ݺ����ꡣ���ǿ���ͨ������glViewport���������ô��ڵ�ά��(Dimension)��
    //OpenGLĻ��ʹ��glViewport�ж����λ�úͿ�߽���2D�����ת������OpenGL�е�λ������ת��Ϊ�����Ļ���ꡣ���磬OpenGL�е�����(-0.5, 0.5)�п��ܣ����գ���ӳ��Ϊ��Ļ�е�����(200, 450)��ע�⣬�������OpenGL���귶ΧֻΪ - 1��1�����������ʵ�Ͻ�(-1��1)��Χ�ڵ�����ӳ�䵽(0, 800)��(0, 600)��
    glViewport(0, 0, 400, 300);

    //���û��ı䴰�ڵĴ�С��ʱ���ӿ�ҲӦ�ñ��������ص�
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //��ⴰ���Ƿ�ر�
    while (!glfwWindowShouldClose(window))
    {
        // ����
        processInput(window);

        // ��Ⱦָ��
        //glClearColor������һ��״̬���ú�����\
        ��glClear��������һ��״̬ʹ�õĺ����� ��ʹ���˵�ǰ��״̬����ȡӦ�����Ϊ����ɫ��\
        ����ʹ��һ���Զ������ɫ�����Ļ����ÿ���µ���Ⱦ������ʼ��ʱ����������ϣ��������\
        �����������ܿ�����һ�ε�������Ⱦ���
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //���ܵĻ���λ��GL_COLOR_BUFFER_BIT��GL_DEPTH_BUFFER_BIT��GL_STENCIL_BUFFER_BIT
        glClear(GL_COLOR_BUFFER_BIT);

        // ��鲢�����¼�����������
        //�ύ����ɫ���壨����һ��������GLFW����ÿһ��������ɫֵ�Ĵ󻺳壩
        glfwSwapBuffers(window);
        //���������û�д���ʲô�¼�������������롢����ƶ��ȣ������´���״̬�������ö�Ӧ�Ļص�����
        glfwPollEvents();
    }
    //����Ⱦѭ��������������Ҫ��ȷ�ͷ�/ɾ��֮ǰ�ķ����������Դ��
    glfwTerminate();
    return 0;
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}



********************************************************************************/




















/************************* DEMO 1
// GLEW  
#define GLEW_STATIC  
#include "GL/glew.h" 
// GLFW  
#include "GLFW/glfw3.h"


// Function prototypes  
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions  
const GLuint WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop  
int main()
{
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
    // Init GLFW  
    glfwInit();
    // Set all the required options for GLFW  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions  
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // Set the required callback functions  
    glfwSetKeyCallback(window, key_callback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions  
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers  
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Define the viewport dimensions  
    glViewport(0, 0, WIDTH, HEIGHT);

    // Game loop  
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions  
        glfwPollEvents();

        // Render  
        // Clear the colorbuffer  
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap the screen buffers  
        glfwSwapBuffers(window);
    }

    // Terminate GLFW, clearing any resources allocated by GLFW.  
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW  
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    std::cout << key << std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
*************************************************************************************/