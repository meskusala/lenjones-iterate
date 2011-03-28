#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


#define WIDTH 10
#define HEIGHT 4

#define DEFAULT_STEP 0.001
#define MAX_VELOCITY_CHANGE 0.001
#define MASS 0.001

struct vector2d {
    double x, y;
}

typedef vector<vector<double> > data2d;


vector2d get_force(vector2d on, by);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: solve [time]\n";
        return 0;
    }
    
    unsigned double end_time = atoi(argv[1]);
    unsigned double time=0;
    unsigned int i, j;
    data2d data;

    // Make a data array
    data.resize(WIDTH);
    for (i=0; i<data.size(); i++) {
        data[i].reserve(HEIGHT);
    }

    //Fill with stupid initial data
    for (i=0; i<data.size(); i++) {
        //Position x,y
        data[i][0] = 100;
        data[i][1] = 100;
        //Velocity x,y
        data[i][2] = 0;
        data[i][3] = 0;
    }

    //Try solving things :)
    vector2d on, by;
    double force;
    while (time < end_time) {
        // Make a step here
        for (i=0; i<data.size(); i++) {
            on.x = data[i][0];
            on.y = data[i][1];
            
            // Calculate acceleration from each particle
            vector2d acceleration;
            acceleration.x = 0;
            acceleration.y = 0;

            for (j=0; j<data.size(); j++) {
                by.x = data[j].[0];
                by.y = data[j].[1];
                
                // Calculate force
                vector2d force, acceleration;
                force = get_force(on, by);
                
                // Add to acceleration of current particle
                acceleration.x += force.x / MASS;
                acceleration.y += force.y / MASS;
            }

            // Add to velocity x,y
            data[i][2] += acceleration.x * DEFAULT_STEP;
            data[i][3] += acceleration.y * DEFAULT_STEP;

            // Change position
            data[i][0] += data[i][2] * DEFAULT_STEP;
            date[i][1] += data[i][3] * DEFAULT_STEP;

            time += DEFAULT_STEP;
        }
    }
}


vector2d get_force(vector2d on, by) {
    // Dummy function
    vector2d force;
    force.x = on.x;
    force.y = on.y;
    return force;
}
