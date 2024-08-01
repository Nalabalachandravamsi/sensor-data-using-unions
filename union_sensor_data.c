#include <stdio.h>
union device {
    struct sensor {
        char temperature;
        char humidity;
        char wind_speed;
        char solar_intensity;
    } formatted;
    char raw_data[4];
};
void read_sensor_data(union device *data);
int main() {
    union device data;
    read_sensor_data(&data);
    int press;
    printf("Press 1 to see temperature :\n");
    printf("Press 2 to see humidity :\n");
    printf("Press 3 to see wind speed :\n");
    printf("Press 4 to see solar intensity :\n");
    scanf("%d", &press);
    if (press == 1) {
        printf("The temperature is: %d celceius\n", data.formatted.temperature);
    }
    if (press == 2) {
        printf("The humidity is: %d percent\n", data.formatted.humidity);
    }
    if (press == 3) {
        printf("The wind speed is: %d kmph\n", data.formatted.wind_speed);
    }
    if (press == 4) {
        printf("The solar intensity is: %d W/m2\n", data.formatted.solar_intensity);
    }

    return 0;
}
void read_sensor_data(union device *data) {
    data->raw_data[0] = 0x28;  // temperature
    data->raw_data[1] = 0x40;  // humidity
    data->raw_data[2] = 0x44;  // wind_speed
    data->raw_data[3] = 0x51;  // solar_intensity
}
