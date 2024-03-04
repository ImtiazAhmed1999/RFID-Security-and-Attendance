# RFID-Security-and-Attendance
<p> Conventional work environments grapple with data fragmentation, security threats, and inefficiencies, burdened by laborious manual methods prone to errors. Smart automation technologies like mobile apps, environmental sensors, RFID security, and cloud-based data monitoring offer solutions for heightened security and efficiency. The project's aim is to deliver a comprehensive smart workplace system featuring simple component control via a mobile app, alongside cloud-based data monitoring, all geared towards maximizing productivity and operational efficiency. </p>
<p><b>SYSTEM ARCHITECTURE:<br></b>
The proposed system integrates various IoT components to create a smart workplace environment that enhances security, access control, and environmental monitoring. The architecture consists of several interconnected modules, each serving specific functions and interacting with one another to achieve comprehensive workplace management.</p>
<p><b>Hardware Components:</b><br>
 At its core, the system employs an ESP32 microcontroller for centralized data processing, communication, and control. Interfaced with the ESP32 is the RDM6300 RFID module, facilitating secure entry by validating RFID tags assigned to employees. A servo motor operates the door mechanism, granting access upon successful RFID tag verification. Environmental conditions are monitored by strategically placed sensors, including the DHT11 temperature and humidity sensor, providing real-time data for optimizing indoor comfort and safety. Additionally, an OLED display provides users with immediate feedback on access attempts, displaying acceptance or denial messages. To enhance security measures, a buzzer alerts users to unauthorized access attempts or potential hazards.</p>
 <p>Powering the system is a 12V battery regulated by an LM2596 buck converter, delivering a stable 5V supply to all components for efficient operation and extended battery life. The system draws power from the general AC supply of the room using an AC/DC converter to convert the AC voltage to 12V DC. Subsequently, the LM2596 buck converter further regulates this voltage to 5V DC, powering the ESP32 and other devices. Moreover, a 12V DC backup source ensures uninterrupted power supply in case of load shedding or disruptions, enhancing system reliability. Additionally, the system utilizes the MOSFET IRF7540 for centralized control of room components, enabling remote management and enhancing operational efficiency. Together, these hardware components create a robust framework for a smart workplace environment, seamlessly integrating access control, environmental monitoring, and user interaction functionalities.</p><br>
 <b>Circuit diagram: </b><br>
 
 
