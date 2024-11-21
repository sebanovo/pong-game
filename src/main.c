#include <raylib.h>
#include <stdio.h>
#include <math.h>

// window
const float screen_width = 1000;
const float screen_height = 650;
const float x_off_set = 50;
const float radius_center_circle = 50.0f;
const int font_size = 50;
const unsigned int max_score = 50;

typedef enum
{
    PLAYER1_WIN,
    PLAYER2_WIN,
    ONGOING
} WinnerState;

// ball
Vector2 ball_position = { screen_width / 2, screen_height / 2 }; // x, y
Vector2 ball_speed = { 10.0f, 10.0f };                           // dx , dy -> speed = dx/dy
const float ball_radius = 10;

// paddle
const float paddle_width = 20;
const float paddle_height = 100;
const float paddle_speed_y_axis = 10;

// player1
Vector2 player1_position = { x_off_set, screen_width / 3 }; // x, y
unsigned int player1_score = 0;

// player2
Vector2 player2_position = { screen_width - x_off_set - paddle_width, screen_width / 3 }; // x, y
unsigned int player2_score = 0;

void draw_ball()
{
    DrawCircleV(ball_position, ball_radius, WHITE);
}

void draw_paddles(Rectangle rec1, Rectangle rec2)
{
    DrawRectangleRounded(rec1, 20, 0, WHITE);
    DrawRectangleRounded(rec2, 20, 0, WHITE);
}

void draw_halfway_line()
{
    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
}

void draw_centre_circle()
{
    DrawCircleLines(screen_width / 2, screen_height / 2, radius_center_circle, WHITE);
}

void draw_score()
{
    DrawText(TextFormat("%u", player1_score), screen_width / 4, 10, font_size, RAYWHITE);
    DrawText(TextFormat("%u", player2_score), 3 * screen_width / 4, 10, font_size, RAYWHITE);
}

WinnerState checkWinner()
{
    if(player1_score >= max_score && player1_score > player2_score)
    {
        return PLAYER1_WIN;
    }
    else if(player2_score >= max_score && player2_score > player1_score)
    {
        return PLAYER2_WIN;
    }

    return ONGOING;
}

int main()
{
    InitWindow(screen_width, screen_height, "Ping Pong Game");
    SetTargetFPS(60);

    WinnerState state = ONGOING;
    while(!WindowShouldClose() && state == ONGOING)
    {
        // move player1
        if(IsKeyDown(KEY_W) && player1_position.y > 0)
        {
            player1_position.y -= paddle_speed_y_axis;
        }
        if(IsKeyDown(KEY_S) && player1_position.y < screen_height - paddle_height)
        {
            player1_position.y += paddle_speed_y_axis;
        }

        // move player2
        if(IsKeyDown(KEY_UP) && player2_position.y > 0)
        {
            player2_position.y -= paddle_speed_y_axis;
        }
        if(IsKeyDown(KEY_DOWN) && player2_position.y < screen_height - paddle_height)
        {
            player2_position.y += paddle_speed_y_axis;
        }

        // check collision between ball and boundary
        if(ball_position.x + ball_radius > screen_width)
        {
            ball_position.x = screen_width / 2;
            ball_position.y = screen_height / 2;
            ball_speed.x = -ball_speed.x;
            player1_score++;
        }
        else if(ball_position.x - ball_radius < 0)
        {
            ball_position.x = screen_width / 2;
            ball_position.y = screen_height / 2;
            ball_speed.x = -ball_speed.x;
            player2_score++;
        }
        else if(ball_position.y + ball_radius > screen_height || ball_position.y - ball_radius < 0)
        {
            ball_speed.y = -ball_speed.y;
        }

        // ball movement
        ball_position.x += ball_speed.x;
        ball_position.y += ball_speed.y;

        // check collision between ball and paddles
        Rectangle player1_rec = { player1_position.x, player1_position.y, paddle_width, paddle_height };
        Rectangle player2_rec = { player2_position.x, player2_position.y, paddle_width, paddle_height };

        if(CheckCollisionCircleRec(ball_position, ball_radius, player1_rec))
        {
            ball_position.x = player1_rec.x + player1_rec.width + ball_radius;
            ball_speed.x = fabs(ball_speed.x);
            float delta_y = ball_position.y - (player1_rec.y + player1_rec.height / 2);
            ball_speed.y = delta_y * 0.1f;
        }

        if(CheckCollisionCircleRec(ball_position, ball_radius, player2_rec))
        {
            ball_position.x = player2_rec.x - ball_radius;
            ball_speed.x = -fabs(ball_speed.x);
            float delta_y = ball_position.y - (player2_rec.y + player2_rec.height / 2);
            ball_speed.y = delta_y * 0.1f;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        draw_halfway_line();
        draw_score();

        draw_centre_circle();
        draw_ball();
        draw_paddles(player1_rec, player2_rec);
        EndDrawing();

        state = checkWinner();
    }

    CloseWindow();

    switch(state)
    {
    case PLAYER1_WIN: printf("Player 1 wins!\n"); break;
    case PLAYER2_WIN: printf("Player 2 wins!\n"); break;
    case ONGOING: printf("FIN DEL JUEGO\n"); break;
    }
    return 0;
}
