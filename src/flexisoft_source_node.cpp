#include <sick_flexisoft_pkg/flexisoft_library.h>
#include <sick_flexisoft_pkg/flexisoft_define.h>
#include <sick_flexisoft_pkg/FlexGetStopOperationalSrv.h>



clientSock *Flexisoft = new clientSock("10.147.20.68", 1100);

bool add(sick_flexisoft_pkg::FlexGetStopOperationalSrv::Request  &req,
         sick_flexisoft_pkg::FlexGetStopOperationalSrv::Response &res)
{
  res.success = req.STOP_OPERATIONAL;
  
  ROS_INFO("sending back response: [%B]", res.success);
  return true;
} 



int main(int argc, char **argv)
{

    ros::init(argc, argv, "safety_function");
    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("FlexGetStopOperationalSrv", add);
     ROS_INFO("Ready to add two ints.");

    //sick_flexisoft_pkg::SAFE_SP_AGV SAFE_SP_AGV;
    
    
    ros::Rate loop_rate(30);
    while (ros::ok())
    {
        if (!Flexisoft->connected)
        {
            Flexisoft->connect();
            ROS_INFO("FLEXISOFT CONNECTING....");
        }
        while (ros::ok() && Flexisoft->connected)
        {
            /* code */

            //Flexisoft->tcp_read(DATA_SET_01);
            

            //Flexisoft->tcp_write_all();
            // sleep(1);
            // cout << "running" << endl;
            // ROS_INFO("FLEXISOFT IS RUNNING......");
            ros::spinOnce();
            loop_rate.sleep();

            /*         while (Flexisoft->connected)
        {
            cout<<"running----------------------------"<<endl;
           Flexisoft->connect();
           sleep(1);
        } */
        }
        loop_rate.sleep();
        ros::spinOnce();
    }
    Flexisoft->disconnect();
    ros::spin();
    delete (Flexisoft);

    return 0;
}