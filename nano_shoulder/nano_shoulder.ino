#include <Arduino.h>
#include <AccelStepper.h>

//define pin constants
#define X_DIR 2
#define X_STEP 5
#define Y_DIR 3
#define Y_STEP 6
#define Z_DIR 4
#define Z_STEP 7
#define DRIVER_INTERFACE 1
#define ENABLE_PIN 8 //is 8 according to chatGPT

//define kinematics
const float stepAngle = 0.9;
const int maxSpeed = 1111; //maxRpm = 1000
const int maxAccel = 500; //start small, test higher to 1000-1500

//angle calculations
const float gearRatio = 13.7*4;
const float angleToStepsConst = gearRatio/stepAngle;

const AccelStepper XAxis(DRIVER_INTERFACE, X_STEP, X_DIR);
const AccelStepper YAxis(DRIVER_INTERFACE, Y_STEP, Y_DIR);
const AccelStepper ZAxis(DRIVER_INTERFACE, Z_STEP, Z_DIR);

int getSteps(float angle) {
    float stepsExact = angle*angleToSteps;
    return static_cast<int>(stepsExact);
}

//todo: I2C connection
void setup() {
    Serial.begin(9600);

    //set kinematics
    XAxis.setMaxSpeed(maxSpeed);
    XAxis.setAcceleration(maxAccel);
    YAxis.setMaxSpeed(maxSpeed);
    YAxis.setAcceleration(maxAccel);
    ZAxis.setMaxSpeed(maxSpeed);
    ZAxis.setAcceleration(maxAccel);

    //enable motor
    pinMode(ENABLE_PIN, 8);
    digitalWrite(ENABLE_PIN, LOW);

}

void loop() {

}