// Library to manage window, drawing, etc
#include <raylib.h>

// Define the number of slide
#define NUM_OF_SLIDES 10

// Declare functions
void SetupSlides();
void DrawSlide();
void CloseProgram();

// Struct to hold slide data
typedef struct Slide
{
    // Text
    char *title;
    char *bulletone;
    char *bullettwo;
    char *bulletthree;
    char *name;
    Color color;
    Color background;

    // Images
    Texture image;
    Vector2 imagePos;
    float imageRotation;
    float imageScale;
    bool hasImage;
} Slide;

// Global varibles
int slideIndex = 0;
Slide slides[NUM_OF_SLIDES] = {0};

int main(void)
{
    // Init raylib
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Software Developer");
    ToggleFullscreen();
    SetTargetFPS(60);
    // Setup Slides
    SetupSlides();
    // Main frame loop
    while (!WindowShouldClose())
    {
        /* Advance slides */
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_RIGHT) || GetMouseWheelMove() > 0)
        { if (slideIndex + 1 < NUM_OF_SLIDES) { slideIndex++; }} // Check that the index cant go out of range and advance to next slide
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) || IsKeyPressed(KEY_LEFT) || GetMouseWheelMove() < 0)
        { if (slideIndex > 0) { slideIndex--; } } // Check that the index cant go out of range and decrement the index

        /* Drawing */
        BeginDrawing();
        ClearBackground(slides[slideIndex].background);
        // Draw text for what slide we are on
        DrawText(FormatText("Slide %d %s", slideIndex + 1, slides[slideIndex].name),
                 30,
                 GetScreenHeight() - 25, 10, DARKGRAY);
        /* Draw current slide */
        DrawSlide();
        EndDrawing();
    }
    CloseProgram();
}

void CloseProgram()
{
    for (int i = 0; i < NUM_OF_SLIDES; i++)
    {
        if(slides[i].hasImage)
        {
            UnloadTexture(slides[i].image);
        }
    }
    CloseWindow();
    return 0;
}


void DrawSlide()
{
    if (slides[slideIndex].hasImage)
    {
        DrawTextureEx(slides[slideIndex].image,
            slides[slideIndex].imagePos,
            slides[slideIndex].imageRotation,
            slides[slideIndex].imageScale, WHITE
        );
    }
    DrawText(slides[slideIndex].title, 20, 20, 50, slides[slideIndex].color);        // Title
    DrawText(slides[slideIndex].bulletone, 60, 100, 30, slides[slideIndex].color);   // Bullet one
    DrawText(slides[slideIndex].bullettwo, 60, 200, 30, slides[slideIndex].color);   // Bullet two
    DrawText(slides[slideIndex].bulletthree, 60, 300, 30, slides[slideIndex].color); // Bullet three
}

void SetupSlides()
{
    /* Setup slides */
    // Title
    slides[0].title = "Software Developer";
    slides[0].name = "Title";
    slides[0].bulletone = " ";
    slides[0].bullettwo = " ";
    slides[0].bulletthree = " ";
    slides[0].color = LIGHTGRAY;
    slides[0].background = BLACK;
    slides[0].hasImage = true;
    slides[0].image = LoadTexture("Images/Keyboard.png");
    slides[0].imageScale = 4;
    slides[0].imagePos = (Vector2) { (GetScreenWidth() / 2) - ((slides[0].image.width / 2) * slides[0].imageScale),
        ((float)GetScreenHeight() * (2.0f / 3.0f)) - ((slides[0].image.height / 2) * slides[0].imageScale)
    };
    slides[0].imageRotation = 0;

    // Introduction
    slides[1].title = "What is a software dev?";
    slides[1].name = "Introduction";
    slides[1].bulletone = "- Aka computer programmer";
    slides[1].bullettwo = "- Writes Applications for computers";
    slides[1].bulletthree = "- Ex: Bill Gates";
    slides[1].color = LIGHTGRAY;
    slides[1].background = BLACK;

    // Education
    slides[2].title = "Education requirements";
    slides[2].name = "Education";
    slides[2].bulletone = "- Most have a Bachelor's degree";
    slides[2].bullettwo = "- Certifications for programming languages";
    slides[2].bulletthree = "- General certifications";
    slides[2].color = LIGHTGRAY;
    slides[2].background = BLACK;

    // Duties
    slides[3].title = "Tasks";
    slides[3].name = "Tasks and duties";
    slides[3].bulletone = "- Write programs";
    slides[3].bullettwo = "- Debug programs";
    slides[3].bulletthree = "- Expand and improve software";
    slides[3].color = LIGHTGRAY;
    slides[3].background = BLACK;

    // Environment
    slides[4].title = "Work environment";
    slides[4].name = "Work environment";
    slides[4].bulletone = "- Normally work alone";
    slides[4].bullettwo = "- Can write code anywhere";
    slides[4].bulletthree = "- Lot of sitting at a computer";
    slides[4].color = LIGHTGRAY;
    slides[4].background = BLACK;

    // Salary
    slides[5].title = "Salary";
    slides[5].name = "Salary";
    slides[5].bulletone = "- Lowest 10: $48790";
    slides[5].bullettwo = "- Highest 10: $134630";
    slides[5].bulletthree = "- Median: $84280";
    slides[5].color = LIGHTGRAY;
    slides[5].background = BLACK;

    // Benefits
    slides[6].title = "Benefits";
    slides[6].name = "Benefits";
    slides[6].bulletone = "- Ability to freelance";
    slides[6].bullettwo = "- Not a lot of movement";
    slides[6].bulletthree = "- Lots of demand";
    slides[6].color = LIGHTGRAY;
    slides[6].background = BLACK;

    // Promotion
    slides[7].title = "Levels of a software dev";
    slides[7].name = "Promotions";
    slides[7].bulletone = "- Junior software developer";
    slides[7].bullettwo = "- Senior software developer";
    slides[7].bulletthree = "- Software architect";
    slides[7].color = LIGHTGRAY;
    slides[7].background = BLACK;

    // Outlook
    slides[8].title = "Job forecast";
    slides[8].name = "Outlook";
    slides[8].bulletone = "- Expected 21% growth 2018-2028";
    slides[8].bullettwo = "- Can lead to many other Jobs";
    slides[8].bulletthree = "   - Game programmer, Software analyist";
    slides[8].color = LIGHTGRAY;
    slides[8].background = BLACK;

    // Works cited
    slides[9].title = " ";
    slides[9].name = " ";
    slides[9].bulletone = " ";
    slides[9].bullettwo = " ";
    slides[9].bulletthree = " ";
    slides[9].color = LIGHTGRAY;
    slides[9].background = BLACK;
    slides[9].hasImage = true; // Tell the drawing function that there is an image
    Image tmpImage = LoadImage("Images/WorksCited.png"); // Load image has tmp
    ImageColorContrast(&tmpImage, 100);
    ImageColorGrayscale(&tmpImage);
    ImageColorInvert(&tmpImage); // Invert the colors
    slides[9].image = LoadTextureFromImage(tmpImage); // Convert image to texture
    UnloadImage(tmpImage); // Unload the tmp image
    slides[9].imageScale = GetScreenHeight() / slides[9].image.height; // Figure out image scaling
    slides[9].imagePos.x = (GetScreenWidth() / 2) - (slides[9].image.width / 2);
    slides[9].imagePos.y = 0;
    slides[9].imageRotation = 0;
}