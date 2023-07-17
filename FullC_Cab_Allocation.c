
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>
#include<string.h>

struct Pick_Up_Time{
    int MM;
    int HH;
};
struct userInfo
{
    char name[20];
    char street[30];
    char location[20];
    char modeOfTravel[20];
    char destination[20];
    struct Pick_Up_Time tim;
};

struct CabDriver {
    char name[50];
    char licensePlate[20];
    int node;
    char type[20];
};

int main()
{
    
    int opt;
    int min_node=0;
    int total_fare=0;
    int total_dist=0;
    int Cancellation(bool,int);
    struct userInfo uInfo;
    printf("Enter name: \n");
    scanf("%s",uInfo.name);
    printf("Enter pick-up location: \n");
    scanf(" %[^\n]s",uInfo.location);
    printf("Enter destination: \n");
    scanf(" %[^\n]s",uInfo.destination);
    printf("Enter mode of travel: \n");
    scanf("%s",uInfo.modeOfTravel);
    printf("Select: 1.Immediate Pickup   2.Later pickup\n");
    scanf("%d",&opt);
    if(opt==2)
    {
        printf("Enter time asm HH MM: \n");
        scanf("%d %d",&uInfo.tim.HH,&uInfo.tim.MM);
    }
    
    int loc_source=mapping_locations(uInfo.location);
    int loc_dest=mapping_locations(uInfo.destination);
    
    //for mapping function
    //Mapping    
    int  map[11][11]= {
          //{R,B,A,C,D,E,F,G,H,K,J}
		   { 0,4,0,0,0,0,0,0,0,0,0},
		   { 4,0,2,0,0,0,6,0,0,0,0},
		   { 0,2,0,2,0,6,0,0,0,0,0},
		   { 0,0,2,0,6,0,0,0,0,0,0},
		   { 0,0,0,6,0,1,0,0,0,0,0},
		   { 0,0,6,0,1,0,1,0,0,0,2},
		   { 0,6,0,0,0,1,0,1,0,0,0},
		   { 0,0,0,0,0,0,1,0,7,2,0},
		   { 0,0,0,0,0,0,0,7,0,0,0},
		   { 0,0,0,0,0,0,0,2,0,0,3},
           { 0,0,0,0,0,2,0,0,0,3,0} };



    //Initializing values
    int distances[11]={100,100,100,100,100,100,100,100,100,100,100};
    distances[loc_source]=0;

    int unvisited[11]={0,1,2,3,4,5,6,7,8,9,10};
    int count=10;

    //Function call
    shortest_distance(map,loc_source,distances,unvisited,count);
    
    //getting the closest node
    min_node=cab_min_distance(distances);
    total_dist=total_distance(distances,loc_dest);
    printf("%d\n",total_dist);
    
    //printing the fare
    total_fare = fare_calculation(uInfo,total_dist,opt);
    printf("Total fare: %d\n",total_fare);
    
    //cancelling
    printf("Do you wish to cancel the ride?(1 for yes or 0 for no): ");
    int yn;
    scanf("%d",&yn);
    bool y_n=(bool)yn;
    total_fare=Cancellation(y_n,total_fare);
    printf("Total fare with cancellation: %d",total_fare);
    
    //writing customer data to file
    writeUserDataToFile(uInfo,total_fare);
    
    // Read cab driver details from file
    struct CabDriver drivers[13];
    int numDrivers;
    readCabDrivers(drivers, &numDrivers);

    // Print details of the nearest cab driver at the source node
    printNearestCabDriver(min_node,drivers);
    
    return 0;
}

//map existing locations to nodes on the map
int mapping_locations(char location[])
{
    int loc;
    for (int i = 0; i < strlen(location); i++) {
        location[i] = tolower(location[i]);
    }
    char locations[11][20]={"cold stone","nilgiris","vinayakar temple","green services","spar","amman temple","mayfair plastics","anand nursery","hira realtors","cross street","lakme salon"};
    for(int i=0; i<11; i++)
    {
        if(strcmp(location,locations[i])==0)
            loc=i;
    }
    return loc;
}

//int shortest_distance(int map[11][11],int source,int distances[],int unvisited[],int count);

//searching for the element position
int Search(int array[], int start_index, int end_index, int element){
   if (end_index >= start_index){
      int middle = start_index + (end_index - start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] > element)
         return Search(array, start_index, middle-1, element);
      return Search(array, middle+1, end_index, element);
   }
   return -1;
}

//Dijkstra function definition
int shortest_distance(int map[11][11],int source,int distances[],int unvisited[],int count)
{
    
     
    
    
    //Initializing next source values -->next source is the closest node
    int next_source_dist=110;
    int next_source=100;
    
    
    
    //we iterate through the unvisited nodes
    for(int i=0;i<=11;i++)
    {
        
        
        
        if(map[source][i]!=0)//we only check for adjaecent nodes
        {
            //update distance between nodes if it is shorter than present distance
            if(distances[source]+map[source][i]<distances[i])
            {
                distances[i]=distances[source]+map[source][i];
                
            }    
                //store the value of closest node for next source
                if (map[source][i]<next_source_dist && Search(unvisited,0,10,i)!=-1)
                {
                    next_source_dist=map[source][i];
                    next_source=i;
                
                }
                
            
        }
    }
    
    
    
    
    
        
    //removing the source node from unvisited
    
    int c=Search(unvisited, 0 , count ,source);
    
    
    
    for( c ;c<count;c++)
        unvisited[c] = unvisited[c+1];
    unvisited[count]=0;
    count--;
    
    
    
    
    
    if (next_source>10 || next_source<0)
        next_source=unvisited[0];
    
    
    //if unvisited is empty
    if (count!=-1)
        return shortest_distance(map,next_source,distances,unvisited,count);
    else
        return 0;

}

//finding min distance
int cab_min_distance(int distances[])
{
    int min=1000,index=0;
    for(int i=0;i<11;i++)
    {
        if(distances[i]!=0 && distances[i]<min)
        {
            min=distances[i];
            index=i;
        }
    }
    return index;
}

//total distance
int total_distance(int distances[],int loc_dest)
{
    int total_dist;
    total_dist=distances[loc_dest];
    return total_dist;
}

//fare calculation
int fare_calculation(struct userInfo u, int distance,int opt)
{
    //min fare for 2km
    int min_fare=25;
    int per_km_fare=12;
    int per_km_fare_peak=16;
    int total_fare=25;
    int diff=0;
    
    //advanced charge checking
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    if(opt==2)
    {
        if(abs(u.tim.HH-tm.tm_hour)>1)
            total_fare=total_fare+45;
        else
        {
            if(u.tim.MM>tm.tm_min)
            {
                diff=abs(u.tim.MM-tm.tm_min-60);
            }
            else
            {
                diff=abs(u.tim.MM-tm.tm_min);
            }
            if(diff>45)
                total_fare=total_fare+45;
        }
        if(u.tim.HH>=17 && u.tim.HH<=21)
            total_fare=total_fare+(distance-2)*per_km_fare_peak;
        else
            total_fare=total_fare+(distance-2)*per_km_fare;
    }
    
    else
    {
        if(tm.tm_hour>=17 && tm.tm_hour<=21)
            total_fare=total_fare+(distance-2)*per_km_fare_peak;
        else
            total_fare=total_fare+(distance-2)*per_km_fare;
    }
    
    return total_fare;
}

//Cancellation
int Cancellation(bool y_n,int total_fare)
{
    if(y_n)
    {
        total_fare= 0.04*total_fare;
    }
    return total_fare;
}

//writing customer data
void writeUserDataToFile(struct userInfo u,int TF) {
    FILE *file = fopen("customers.txt", "a");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    fprintf(file, "%s ;%s ;%s ;%d\n", u.name, u.location, u.destination, TF);
    fclose(file);
}

//cabdriverdata
void readCabDrivers(struct CabDriver drivers[], int *numDrivers) {
    FILE *file = fopen("cab_drivers.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    *numDrivers = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *name = strtok(line, ";");
        char *licensePlate = strtok(NULL, ";");
        char *nodeStr = strtok(NULL, ";");
        char *type = strtok(NULL, ";");

        strcpy(drivers[*numDrivers].name, name);
        strcpy(drivers[*numDrivers].licensePlate, licensePlate);
        drivers[*numDrivers].node = atoi(nodeStr);
        strcpy(drivers[*numDrivers].type, type);

        (*numDrivers)++;
    }

    fclose(file);
}

//printing cab details
void printNearestCabDriver(int index,struct CabDriver drivers[])
{
    if (index != -1) {
        printf("Nearest Cab Driver:\n");
        printf("Name: %s\n", drivers[index].name);
        printf("License Plate: %s\n", drivers[index].licensePlate);
        printf("Location: %d\n", index);
        printf("Type: %s\n", drivers[index].type);
    } 
}