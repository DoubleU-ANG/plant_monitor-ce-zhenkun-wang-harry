# plant_monitor-ce-zhenkun-wang-harry
This project is a plant monitor system, including a plant monitor used to monitor the state of the plant(temperature, humidity, moisture) and a blinking monster to remind whether there is anything approaching.
## plant monitor
It has DHT22, the sensor used to gain the data of plant(temperature, humidity, moisture) and esp8266 to upload the data to the MQTT server
![WechatIMG17](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/6661fec5-6c41-4d19-a25b-038c13d6825c)
![upload_data](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/4856acfd-611e-4a75-b611-499a4dc8d267)
A servo, used to pretend watering, and a light have also been used to warn and water the plant when the moisture is lower than 50 (which means the plant need water)
https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/7c76f609-66e5-49fd-b650-e7fefba67df9

Need water:
![WechatIMG25](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/4f6174ae-f39d-4231-85cb-504043c5a3a8)
the light turns on:
![WechatIMG19](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/ac116bbd-8261-4d77-98f3-eab70a27971a)
the servo works to add water:
https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/864d2f17-206f-4221-ad3c-8a304c3fb188

Enough water:
![WechatIMG26](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/d58c2744-9e43-42ad-9e4b-e848c53c73b5)
the light turns off:
![WechatIMG20](https://github.com/DoubleU-ANG/plant_monitor-ce-zhenkun-wang-harry/assets/100694831/e30f5dcb-34d0-4021-a636-5f9db830cbd2)
