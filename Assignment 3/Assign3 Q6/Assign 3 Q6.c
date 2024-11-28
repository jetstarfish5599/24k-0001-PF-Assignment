// Roll#24k-0001 Name:Masoom Khan Assignment:3 Q6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definitions

typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} Weather;

typedef struct {
    char cropType[50];
    int growthStage;
    float expectedYield;
    Weather* weather;
} Crop;

typedef struct {
    char equipmentName[50];
    int operationalStatus; // 1 for operational, 0 for not in use
    float fuelLevel;       // Percentage
    char activitySchedule[100];
} Equipment;

typedef struct {
    float nutrientLevel;
    float pHLevel;
    int pestActivity; // 1 for active pests, 0 for none
} Sensor;

typedef struct {
    char gpsCoordinates[100];
    float soilHealth;
    float moistureLevel;
    Crop* crops;
    int numCrops;
    Equipment* equipment;
    int numEquipment;
    Sensor* sensors;
    int numSensors;
} Field;

typedef struct {
    char regionName[50];
    Field* fields;
    int numFields;
    float aggregateYieldPrediction;
    char emergencyPlan[200];
} RegionalHub;

// Function Prototypes
Field* createField(int numCrops, int numEquipment, int numSensors);
void inputFieldData(Field* field);
void displayFieldData(const Field* field);
RegionalHub* createRegionalHub(int numFields);
void inputRegionalHubData(RegionalHub* hub);
void displayRegionalHubData(const RegionalHub* hub);
void freeField(Field* field);
void freeRegionalHub(RegionalHub* hub);
//start main
int main() {
    // Example: Create a Regional Hub with 2 fields
    int numFields = 2;
    RegionalHub* hub = createRegionalHub(numFields);
    inputRegionalHubData(hub);
    displayRegionalHubData(hub);
    freeRegionalHub(hub);

    return 0;
}
//end main
// Function Implementations

Field* createField(int numCrops, int numEquipment, int numSensors) {
    Field* field = (Field*)malloc(sizeof(Field));
    field->crops = (Crop*)malloc(numCrops * sizeof(Crop));
    field->numCrops = numCrops;
    field->equipment = (Equipment*)malloc(numEquipment * sizeof(Equipment));
    field->numEquipment = numEquipment;
    field->sensors = (Sensor*)malloc(numSensors * sizeof(Sensor));
    field->numSensors = numSensors;
    return field;
}

void inputFieldData(Field* field) {
    printf("Enter GPS coordinates: ");
    scanf(" %[^\n]", field->gpsCoordinates);

    printf("Enter soil health (0-100): ");
    scanf("%f", &field->soilHealth);

    printf("Enter moisture level (0-100): ");
    scanf("%f", &field->moistureLevel);

    // Input Crops
    for (int i = 0; i < field->numCrops; i++) {
        printf("Enter crop type for Crop %d: ", i + 1);
        scanf(" %[^\n]", field->crops[i].cropType);
        printf("Enter growth stage for Crop %d: ", i + 1);
        scanf("%d", &field->crops[i].growthStage);
        printf("Enter expected yield for Crop %d: ", i + 1);
        scanf("%f", &field->crops[i].expectedYield);

        field->crops[i].weather = (Weather*)malloc(sizeof(Weather));
        printf("Enter temperature for Crop %d: ", i + 1);
        scanf("%f", &field->crops[i].weather->temperature);
        printf("Enter rainfall for Crop %d: ", i + 1);
        scanf("%f", &field->crops[i].weather->rainfall);
        printf("Enter wind speed for Crop %d: ", i + 1);
        scanf("%f", &field->crops[i].weather->windSpeed);
    }

    // Input Equipment
    for (int i = 0; i < field->numEquipment; i++) {
        printf("Enter equipment name for Equipment %d: ", i + 1);
        scanf(" %[^\n]", field->equipment[i].equipmentName);
        printf("Enter operational status (1 for active, 0 for inactive): ");
        scanf("%d", &field->equipment[i].operationalStatus);
        printf("Enter fuel level (0-100%%): ");
        scanf("%f", &field->equipment[i].fuelLevel);
        printf("Enter activity schedule: ");
        scanf(" %[^\n]", field->equipment[i].activitySchedule);
    }

    // Input Sensors
    for (int i = 0; i < field->numSensors; i++) {
        printf("Enter nutrient level for Sensor %d: ", i + 1);
        scanf("%f", &field->sensors[i].nutrientLevel);
        printf("Enter pH level for Sensor %d: ", i + 1);
        scanf("%f", &field->sensors[i].pHLevel);
        printf("Enter pest activity (1 for active, 0 for inactive): ");
        scanf("%d", &field->sensors[i].pestActivity);
    }
}

void displayFieldData(const Field* field) {
    printf("\nField GPS Coordinates: %s\n", field->gpsCoordinates);
    printf("Soil Health: %.2f\n", field->soilHealth);
    printf("Moisture Level: %.2f\n", field->moistureLevel);

    printf("\nCrops:\n");
    for (int i = 0; i < field->numCrops; i++) {
        printf("  Crop %d:\n", i + 1);
        printf("    Type: %s\n", field->crops[i].cropType);
        printf("    Growth Stage: %d\n", field->crops[i].growthStage);
        printf("    Expected Yield: %.2f\n", field->crops[i].expectedYield);
        printf("    Weather - Temp: %.2f, Rainfall: %.2f, Wind: %.2f\n",
               field->crops[i].weather->temperature,
               field->crops[i].weather->rainfall,
               field->crops[i].weather->windSpeed);
    }

    printf("\nEquipment:\n");
    for (int i = 0; i < field->numEquipment; i++) {
        printf("  Equipment %d:\n", i + 1);
        printf("    Name: %s\n", field->equipment[i].equipmentName);
        printf("    Status: %d\n", field->equipment[i].operationalStatus);
        printf("    Fuel Level: %.2f\n", field->equipment[i].fuelLevel);
        printf("    Schedule: %s\n", field->equipment[i].activitySchedule);
    }

    printf("\nSensors:\n");
    for (int i = 0; i < field->numSensors; i++) {
        printf("  Sensor %d:\n", i + 1);
        printf("    Nutrient Level: %.2f\n", field->sensors[i].nutrientLevel);
        printf("    pH Level: %.2f\n", field->sensors[i].pHLevel);
        printf("    Pest Activity: %d\n", field->sensors[i].pestActivity);
    }
}

RegionalHub* createRegionalHub(int numFields) {
    RegionalHub* hub = (RegionalHub*)malloc(sizeof(RegionalHub));
    hub->fields = (Field*)malloc(numFields * sizeof(Field));
    hub->numFields = numFields;
    return hub;
}

void inputRegionalHubData(RegionalHub* hub) {
    printf("Enter region name: ");
    scanf(" %[^\n]", hub->regionName);
    printf("Enter aggregate yield prediction: ");
    scanf("%f", &hub->aggregateYieldPrediction);
    printf("Enter emergency plan: ");
    scanf(" %[^\n]", hub->emergencyPlan);

    for (int i = 0; i < hub->numFields; i++) {
        printf("\nEntering data for Field %d:\n", i + 1);
        hub->fields[i] = *createField(2, 2, 2);
        inputFieldData(&hub->fields[i]);
    }
}

void displayRegionalHubData(const RegionalHub* hub) {
    printf("\nRegion Name: %s\n", hub->regionName);
    printf("Aggregate Yield Prediction: %.2f\n", hub->aggregateYieldPrediction);
    printf("Emergency Plan: %s\n", hub->emergencyPlan);

    for (int i = 0; i < hub->numFields; i++) {
        printf("\nField %d:\n", i + 1);
        displayFieldData(&hub->fields[i]);
    }
}

void freeField(Field* field) {
    for (int i = 0; i < field->numCrops; i++) {
        free(field->crops[i].weather);
    }
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
}

void freeRegionalHub(RegionalHub* hub) {
    for (int i = 0; i < hub->numFields; i++) {
        freeField(&hub->fields[i]);
    }
    free(hub->fields);
    free(hub);
}