# plant_monitor-ce-zhenkun-wang-harry
This project is a plant monitor system, including a plant monitor used to monitor the state of the plant(temperature, humidity, moisture) and then upload the data to the MQTT server, a blinking monster to remind whether there is anything approaching, and a rasp-pi which can act as a datastore and then process the data by using some powerful tools.
## plant monitor
It has DHT22, the sensor used to gain the data of plant(temperature, humidity, moisture), esp8266 to collect and upload the data to the MQTT server and a light and a servo.
![WechatIMG17](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/6661fec5-6c41-4d19-a25b-038c13d6825c)
![upload_data](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/4856acfd-611e-4a75-b611-499a4dc8d267)
A servo, used to pretend watering, and a light have also been used to warn and water the plant when the moisture is lower than 50 (which means the plant need water)
![servo](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/4ca95131-d9d8-491c-a1e7-313afe856c62)

Need water(moisture lower than 50):
![WechatIMG25](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/4f6174ae-f39d-4231-85cb-504043c5a3a8)
the light turns on:
![WechatIMG19](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/ac116bbd-8261-4d77-98f3-eab70a27971a)
the servo works to add water:
https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/50bdfb72-e570-4cdb-a66d-0f2afef10ab1


Enough water(moisture higher than 50):
![WechatIMG26](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/d58c2744-9e43-42ad-9e4b-e848c53c73b5)
the light turns off:
![WechatIMG20](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/e30f5dcb-34d0-4021-a636-5f9db830cbd2)

## blinking monster:
It has ultrasonic, which used to detect the distance, and a light and a buzzer to generate warning signal.
When something strange approach the plant, the monster will be blinking(buzzer and LED light), and it blinks faster when thing approaches closer.
https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/7b8f6966-9113-405a-b7ea-55882e3780cc

## rasp-pi:
It has telegraf to collect the data, influxdb to store the data and granafa to visualize the data. So we can use these three tools to make our data more readable and beautiful.

influxdb get data from telegraf:
<img width="1244" alt="influxdb1" src="https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/50f81c36-9ede-4b38-9fd5-5dce3d5df410">
grafana visualize data:

<img width="416" alt="image" src="https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/b58ddae7-6cf7-4f58-a682-ca1a379def76">



# Problems that I met:
I have failed to reach the data in the MQTT server for many times, and all caused by a same problem -- I did not input the right path, which is really easy to be ignored. So the next time I do the same task, I will check the path firstly to make sure that I have input the right one. 

# Potential function:
## communication between arduino and esp8266 through IIC
I have set up the communication between arduino uno and esp8266 through serial port, which can send some text(for example: I sent 'delay1').
![WechatIMG16](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/d67021fd-d9c3-4020-a7ec-64df264a3034)
![serial_communication](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/9ce7886a-47e5-4745-8f8f-caf3df6e8eaa)
But it is not appropriate to use serial port to communicate in this project because I don't really know which pins are available to be set up as software serial. So it is necessary to build up IIC communication between these two controller. After doing that I can send data of plant from esp8266 to arduino and then develop some more interesting interactions based on those data.

## OLED DISPLAY
There is no screen to show information on the esp8266 and arduino, so it is necessary to add screen on these controller to let user know what is going on. I have make the screen to display some text on the arduino, in the next step I will combine it into the whole project to display some information including temperature, humidity and moisture.


## LATEST EXTENSION
In the latest extension, I add a "mouth" to the plant that can make the system more interactive, which use an OLED screen to display some text based on the condition of the environment.

<img width="159" alt="image" src="https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/b6c7af6e-79a2-4316-a4d1-98fe62427fe3">

<img width="173" alt="image" src="https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/590fb0c2-6c28-4581-9a76-31fedbaebc05">

<img width="173" alt="image" src="https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/0b06262d-fa64-4812-8c17-4e6db460f6bd">

We can see how it interacts with us by asking for help

