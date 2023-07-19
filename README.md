# Cab Hailing Software System

This software system is designed for a cab hailing service. It allows users to request a cab for immediate or later pickup and calculates the fare based on the distance and chosen mode of travel. The system also assigns the nearest available cab driver to the user's location and updates the driver's information after each trip.

## Features

- User input: The system prompts the user to enter their name, pick-up location, destination, mode of travel, and pickup option (immediate or later). For later pickups, the user can specify the desired time.
- Mapping locations: The system maps the input pick-up location and destination to specific nodes on the map.
- Dijkstra's algorithm: The system uses Dijkstra's algorithm to calculate the shortest distance between nodes and determine the total distance traveled.
- Fare calculation: The system calculates the fare based on the mode of travel, total distance, and pickup option. It considers base fare, per kilometer fare, per kilometer fare during peak hours, and advanced booking charges (if applicable).
- Cab driver data: The system reads cab driver details from a file, including their name, license plate, current location node, vehicle type, rating, and number of trips.
- Nearest cab driver assignment: The system assigns the nearest available cab driver to the user's location and displays the driver's details.
- Trip cancellation: The system provides the option to cancel the trip, in which case the fare is recalculated with a cancellation fee.
- Data storage: The system writes the user's data (name, pick-up location, destination, and fare) to a file and updates the cab driver's information after each trip.

## Files

The software system consists of the following files:

- `main.c`: The main program file containing the implementation of the cab hailing system.
- `cab_drivers.txt`: A text file that stores cab driver details, including name, license plate, current location node, vehicle type, rating, and number of trips.
- `distance_from_nodes.txt`: A text file that maps landmark locations to nodes on the map and specifies the distance between landmarks and nodes.
- `customers.txt`: A text file that stores user data, including name, pick-up location, destination, and fare.

## Usage

1. Compile the `main.c` file using a C compiler (e.g., gcc).
2. Make sure the `cab_drivers.txt` and `distance_from_nodes.txt` files are present in the same directory as the compiled program.
3. Run the compiled program.
4. Follow the prompts to enter the user's details, including name, pick-up location, destination, mode of travel, and pickup option.
5. If the user chooses a later pickup option, enter the desired time (hours and minutes).
6. The system will calculate the fare, assign the nearest available cab driver, and display the fare and driver details.
7. The user can choose to cancel the trip or proceed with the booking.
8. If the trip is canceled, the fare with the cancellation fee will be displayed, and the user's data will be stored in the `customers.txt` file.
9. If the trip is confirmed, the fare will be displayed, the user's data will be stored in the `customers.txt` file, and the cab driver's information will be updated in the `cab_drivers.txt` file.

Note: Make sure the input files (`cab_drivers.txt` and `distance_from_nodes.txt`) are formatted correctly as described in the sample files above.

Feel free to customize the code and input files to add more features or modify the existing ones based on your requirements.

Happy cab hailing!
