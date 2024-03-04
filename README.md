# RFID-Security-and-Attendance
<p> Conventional work environments grapple with data fragmentation, security threats, and inefficiencies, burdened by laborious manual methods prone to errors. Smart automation technologies like mobile apps, environmental sensors, RFID security, and cloud-based data monitoring offer solutions for heightened security and efficiency. The project's aim is to deliver a comprehensive smart workplace system featuring simple component control via a mobile app, alongside cloud-based data monitoring, all geared towards maximizing productivity and operational efficiency. </p>
<p><b>SYSTEM ARCHITECTURE:<br></b>
The proposed system integrates various IoT components to create a smart workplace environment that enhances security, access control, and environmental monitoring. The architecture consists of several interconnected modules, each serving specific functions and interacting with one another to achieve comprehensive workplace management.</p>
<p><b>Hardware Components:</b><br>
 At its core, the system employs an ESP32 microcontroller for centralized data processing, communication, and control. Interfaced with the ESP32 is the RDM6300 RFID module, facilitating secure entry by validating RFID tags assigned to employees. A servo motor operates the door mechanism, granting access upon successful RFID tag verification. Environmental conditions are monitored by strategically placed sensors, including the DHT11 temperature and humidity sensor, providing real-time data for optimizing indoor comfort and safety. Additionally, an OLED display provides users with immediate feedback on access attempts, displaying acceptance or denial messages. To enhance security measures, a buzzer alerts users to unauthorized access attempts or potential hazards.</p>
 <p>Powering the system is a 12V battery regulated by an LM2596 buck converter, delivering a stable 5V supply to all components for efficient operation and extended battery life. The system draws power from the general AC supply of the room using an AC/DC converter to convert the AC voltage to 12V DC. Subsequently, the LM2596 buck converter further regulates this voltage to 5V DC, powering the ESP32 and other devices. Moreover, a 12V DC backup source ensures uninterrupted power supply in case of load shedding or disruptions, enhancing system reliability. Additionally, the system utilizes the MOSFET IRF7540 for centralized control of room components, enabling remote management and enhancing operational efficiency. Together, these hardware components create a robust framework for a smart workplace environment, seamlessly integrating access control, environmental monitoring, and user interaction functionalities.</p><br>

 <p><b>Circuit diagram: </b><br>
  
![Schematic_micro project](https://github.com/ImtiazAhmed1999/RFID-Security-and-Attendance/assets/101192574/d375a655-3e29-427e-b8ee-6ff5e6e93159)
 </p><br> <br>

<p>
 <b>Software Components:</b> <br> <br>
 <b>Cloud Platform(Google Sheet):</b> <br>
 The cloud platform, facilitated by Google Sheets, acts as a centralized repository for data storage and management. Attendance records, appliance usage statistics, and environmental monitoring data are stored securely in Google Sheets. The cloud platform ensures data accessibility, scalability, and real-time synchronization, allowing for efficient updates and seamless integration with both the mobile application and the web dashboard.<br>
 To streamline the process of updating Google Sheets with real-time data, the system incorporates IFTTT (If This Then That) integration. IFTTT automates the data update process, enabling immediate synchronization between various components of the system. This integration ensures that changes in attendance records, appliance usage, or environmental data are promptly reflected in the cloud platform.
</p>

<p><b>Mobile Application:</b>
<br>
The custom mobile application, developed using MIT App Inventor environment, serves as a central interface for authorized personnel. This application connects to the core system, providing real-time access to workplace data, appliance usage statistics, and attendance records. It serves as a control center for users to interact with and manage various aspects of the workplace, offering a user-friendly experience.</p>

<p><b>Web Dashboard:</b>
<br>
The cloud platform, facilitated by Google Sheets, acts as a centralized repository for data storage and management. Attendance records, appliance usage statistics, and environmental monitoring data are stored securely in Google Sheets. The cloud platform ensures data accessibility, scalability, and real-time synchronization, allowing for efficient updates and seamless integration with both the mobile application and the web dashboard.</p>

<p><b>Methodology</b>
<br>
The ESP32 and RDM6300 RFID module collaborate for secure access control, validating tags seamlessly. RFID signals activate tags, transmitting unique identifiers to the ESP32 for validation. Upon success, a servo motor opens the gate and triggers a buzzer alert. The servo motor, guided by the microcontroller, ensures controlled entry. The MOSFET IRF7540 regulates fans via HTTP requests, promoting energy efficiency.</p>

<p><b>User Feedback, Security Measures, and Buzzer Integration:</b>
<br>
The OLED display and buzzer collaborate seamlessly to provide immediate user feedback and enhance security. The display offers visual insights into access attempts, while the buzzer serves as an audible alarm, alerting users to unauthorized access attempts or potential hazards.</p>

<p><b>Power Backup Solution:</b>
<br>
The power backup solution, consisting of a 12V battery and an LM2596 buck converter, integrates smoothly with the overall system architecture. This setup ensures a stable 5V supply for prolonged and uninterrupted system operation, even in the face of power disruptions.</p>
<br> 

<p><b>System Testing:</b><br>
<br>
 <b>Prototype working:</b>
 
![deen](https://github.com/ImtiazAhmed1999/RFID-Security-and-Attendance/assets/101192574/d9fc5ff9-e422-4627-b65f-3a275d821dc5)
 
![door-1](https://github.com/ImtiazAhmed1999/RFID-Security-and-Attendance/assets/101192574/d9bf85b8-7376-4c72-8ad1-e254ae9ad6db)
</p>

<p><b>Attendance Information on Google Sheet:</b>
<br>
 
![attendance](https://github.com/ImtiazAhmed1999/RFID-Security-and-Attendance/assets/101192574/47e88229-2e0a-4a19-8374-0754ac30248f)
</p>
