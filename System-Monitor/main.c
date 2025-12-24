#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

void checkBattery(){
    SYSTEM_POWER_STATUS status;

    if(GetSystemPowerStatus(&status)){  // 0=unplugged 1=plugged
        if(status.ACLineStatus == 1){
            printf("Power Source: Plugged In \n");
        } else {
            printf("Power Source: Battery \n");
        }

        // Battery life 255 meeans unknown otherwise its 0-100
        if(status.BatteryLifePercent != 255){
            printf("Battery Life: %d%%\n", status.BatteryLifePercent);
        }else{
            printf("Battery Life: Unknown\n");
        }
    }else{
        printf("Failed to get Power Status");
    }

    
}


void checkMemory(){
    MEMORYSTATUSEX  mem_status;
    mem_status.dwLength = sizeof(MEMORYSTATUSEX);

    if(GlobalMemoryStatusEx(&mem_status)){
        printf("Memory Usage: %ld%%\n", mem_status.dwMemoryLoad);

        double total_gb = mem_status.ullTotalPhys / (1024 * 1020 * 1024);
        double avail_gb = mem_status.ullAvailPhys / (1024 * 1020 * 1024);

        printf("Total Memory: %.2f GB\n", total_gb);
        printf("Available Memory: %.2f GB\n", avail_gb);
    }else{
        printf("Failed to get Memory Status, \nError Code: %ld\n", GetLastError());
    }
    
}

int main(){
    int choice;
    bool is_running = true;

    while(is_running){
        printf("\n===Windows System Monitor===\n");
        printf("1. Checking battery/power \n");
        printf("2. Check Memory(RAM) \n");
        printf("3. Full Report \n");
        printf("4. Exit \n");
        printf("4. Choose Option: ");

        scanf("%d", &choice);

        if(choice == 1){
            // printf("Fetching power info... \n");
            checkBattery();
        }else if(choice == 2){
            // printgit s("Fectching memory info... \n");
            checkMemory();
        }else if(choice == 3){
            checkBattery();
            checkMemory();
        }else if(choice == 4){
            is_running = false;
            printf("Closing... Goodbye \n");
        }else{
            printf("Invalid input\n");
        }
    }

    return 0;
}
