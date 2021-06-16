#include <ros.h>
#include <std_msgs/Int32.h>

int pin[] = {8, 9, 10, 11};

ros::NodeHandle nh;

void messagecb(const std_msgs::Int32& massage)
{
  digitalWrite(pin[massage.data - 1], HIGH - digitalRead(pin[massage.data - 1]));
}

ros::Subscriber<std_msgs::Int32> sub("control_top", &messagecb);

void setup() 
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
}

void loop() 
{
  nh.spinOnce();
  delay(1);
}
