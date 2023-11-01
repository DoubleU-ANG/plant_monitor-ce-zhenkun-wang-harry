# plant_monitor-ce-zhenkun-wang-harry
This project is a plant monitor system, including a plant monitor used to monitor the state of the plant(temperature, humidity, moisture), a blinking monster to remind whether there is anything approaching, and a rasp-pi which can act as a datastore
## plant monitor
It has DHT22, the sensor used to gain the data of plant(temperature, humidity, moisture) and esp8266 to upload the data to the MQTT server
![WechatIMG17](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/6661fec5-6c41-4d19-a25b-038c13d6825c)
![upload_data](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/4856acfd-611e-4a75-b611-499a4dc8d267)
A servo, used to pretend watering, and a light have also been used to warn and water the plant when the moisture is lower than 50 (which means the plant need water)
![servo](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/4ca95131-d9d8-491c-a1e7-313afe856c62)

Need water(moisture lower than 50):
![WechatIMG25](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/4f6174ae-f39d-4231-85cb-504043c5a3a8)
the light turns on:
![WechatIMG19](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/ac116bbd-8261-4d77-98f3-eab70a27971a)
the servo works to add water:
https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/864d2f17-206f-4221-ad3c-8a304c3fb188

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
<img width="1244" alt="influxdb" src="https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/363b11d4-c759-410b-a71c-a21b9d63cba6">
grafana visualize data:
<img width="1244" alt="granama" src="https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/a394c5c9-dc8b-4484-ad08-0e9059e70e3d">

# Problems that I met:
I have failed to reach the data in the MQTT server for many times, and all caused by a same problem -- I did not input the right path, which is really easy to be ignored. So the next time I do the same task, I will check the path firstly to make sure that I have input the right one. 

# Potential function:
I have set up the communication between arduino uno and esp8266, which can send some text(for example: I sent 'delay1').
![WechatIMG16](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/d67021fd-d9c3-4020-a7ec-64df264a3034)
![serial_communication](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/9ce7886a-47e5-4745-8f8f-caf3df6e8eaa)
So I think I can send data of plant from esp8266 to arduino and then develop some more interesting interactions based on those data.

