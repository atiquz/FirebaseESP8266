# FirebaseESP8266 Library

The FirebaseESP8266 library is a versatile and lightweight Arduino library designed to facilitate seamless integration of ESP8266-based devices with Google Firebase Realtime Database. This library allows users to effortlessly send and receive data between their ESP8266 devices and the Firebase Realtime Database, enabling dynamic and real-time communication.

## Getting Started

1. **Installation**: To use the FirebaseESP8266 library, include it in your Arduino IDE and import it into your sketch. Ensure that you have the required dependencies, such as `FirebaseESP8266` and `ESP8266WiFi`.

    ```cpp
    #include <FirebaseESP8266.h>
    #include <ESP8266WiFi.h>
    ```

2. **Initialization**: Create an instance of the `FirebaseESP8266` class, specifying your Firebase Realtime Database URL during initialization.

    ```cpp
    FirebaseESP8266 firebase("PASTE_FIREBASE_REFERENCE_URL");
    ```

3. **Connection**: Connect your ESP8266 device to a WiFi network using your SSID and password.

    ```cpp
    WiFi.begin("SSID", "PASSWORD");
    ```

4. **Data Interaction**: Use the library's methods to send and receive data to and from the Firebase Realtime Database.

    ```cpp
    firebase.setString("Fruits/Product", "Apple");
    firebase.getInt("Fruits/Code");
    ```

5. **JSON Support**: The library supports both JSON and non-JSON modes for data interaction. Toggle JSON mode as needed.

    ```cpp
    firebase.json(true); // Enable JSON mode
    ```

6. **Push Operations**: Utilize push methods for appending data to arrays in Firebase.

    ```cpp
    firebase.pushString("Updates", "Apple");
    ```

7. **Data Retrieval**: Retrieve data from Firebase using appropriate data types.

    ```cpp
    String data1 = firebase.getString("Fruits/Product");
    ```

8. **Delete Data**: Delete data at a specified path in the Firebase Realtime Database.

    ```cpp
    firebase.deleteData("Fruits");
    ```

## Example Usage

See the provided example sketch (`FirebaseESP8266Demo.ino`) for a comprehensive demonstration of the library's features.

## Contributions and Issues

Feel free to contribute to the development of this library by submitting pull requests. If you encounter any issues or have suggestions, please open an issue on the [GitHub repository](https://github.com/your_username/your_repository).

## License

This library is open-source and distributed under the [MIT License](LICENSE).

Happy coding with FirebaseESP8266!
