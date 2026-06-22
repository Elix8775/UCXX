#include "ucxx.h"

void PutPixel(char screen[40][80], int x, int y)
{
    if (x < 0 || x >= 80 || y < 0 || y >= 40)
        return;

    screen[y][x] = '#';
}

void DrawLine(char screen[40][80], int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;

    int err = dx - dy;

    while (true)
    {
        PutPixel(screen, x0, y0);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = err * 2;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    constexpr int WIDTH  = 80;
    constexpr int HEIGHT = 40;

    Vec3 cube[8] =
    {
        {-1,-1,-1},
        { 1,-1,-1},
        { 1, 1,-1},
        {-1, 1,-1},

        {-1,-1, 1},
        { 1,-1, 1},
        { 1, 1, 1},
        {-1, 1, 1}
    };

    int edges[12][2] =
    {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    float angle = 0.f;

    while (true)
    {
        char screen[HEIGHT][WIDTH];

        for (int y = 0; y < HEIGHT; y++)
            for (int x = 0; x < WIDTH; x++)
                screen[y][x] = ' ';

        angle += 1.f;

        Quat rotation(
            Vec3(1.f, 1.f, 0.f).Normalized(),
            angle
        );

        Mat4 model = Mat4::TRS(
            Vec3(0.f, 0.f, -5.f),
            rotation,
            Vec3(1.f, 1.f, 1.f)
        );

        Mat4 projection = Mat4::Perspective(
            70.f,
            float(WIDTH) / float(HEIGHT),
            0.1f,
            100.f
        );

        Mat4 mvp = projection * model;

        int projected[8][2];

        for (int i = 0; i < 8; i++)
        {
            Vec4 p(
                cube[i].m_x,
                cube[i].m_y,
                cube[i].m_z,
                1.f
            );

            Vec4 clip = mvp * p;

            if (clip.m_w != 0.f)
            {
                clip.m_x /= clip.m_w;
                clip.m_y /= clip.m_w;
            }

            int sx = int((clip.m_x + 1.f) * 0.5f * WIDTH);
            int sy = int((1.f - clip.m_y) * 0.5f * HEIGHT);

            projected[i][0] = sx;
            projected[i][1] = sy;
        }

        for (int i = 0; i < 12; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            DrawLine(
                screen,
                projected[a][0],
                projected[a][1],
                projected[b][0],
                projected[b][1]
            );
        }

        std::cout << "\033[2J\033[H";

        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
                std::cout << screen[y][x];

            std::cout << '\n';
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(16)
        );
    }

    return 0;
}