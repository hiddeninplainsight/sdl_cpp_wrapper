#include <iostream>
#include <cassert>
#include <sdl_cpp_collision_detection.h>

using namespace ::std;

#define fixture_description(msg) cout << "Fixture : " << (msg) << endl
#define description(msg) cout << "Test : " << (msg) << endl

void test_collision_detection_tri_point_collision()
{
    fixture_description("collision_detection_tri_point_collision");
    SDL_Point triangle[3]
        {
            { 10, 10 },
            { 20, 10 },
            { 20, 20 }
        };

    description("A point on the edge of the triangle is not collided");
    assert(!sdl::tri_point_collision(triangle, {10, 10}));

    description("Points inside the triangle collided");
    assert(sdl::tri_point_collision(triangle, {12, 11}));
    assert(sdl::tri_point_collision(triangle, {19, 11}));
    assert(sdl::tri_point_collision(triangle, {19, 18}));
}

int main(int argc, char ** argv)
{
    test_collision_detection_tri_point_collision();

    cout << "All tests passed" << endl;
    return 0;
}