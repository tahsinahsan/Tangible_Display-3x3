Tangible Display 3x3    
Youtube Link (https://youtu.be/eHOGDgq4bJI?si=fzmKej1PD4ZZnf2O)
A low-cost tangible display prototype made of 9 physical pixels (9mm x 9mm), each controlled by stepper motors and brake cable mechanisms. The system can visualize depth data using external input such as Kinect.

Features
3x3 physical resolution grid
Each pixel moves vertically to create depth
Stepper motor + brake cable actuation
Controlled using Arduino Mega
Supports external input (e.g., Kinect sensor)
How It Works

Each pixel is driven by a stepper motor connected through a brake cable and tube system. The motors push/pull vertical pins to create height variation, forming a physical surface.

Hardware
Arduino Mega
9 Stepper Motors Nema  
Stepper Motor Drivers x9 
Brake cables + tubes
Frame + pixel pins (9mm x 9mm each)
Optional: Kinect sensor
Software
Arduino code for motor control
(Optional) PC interface for Kinect depth mapping
Setup
Upload Arduino code from /arduino
Connect motors as shown in wiring diagram
Run control script / Kinect interface (if used)
Demo



Future Improvements
Higher resolution grid
Faster actuation
Closed-loop position control
Smoother motion
License

MIT License
