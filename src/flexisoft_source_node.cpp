#include <sick_flexisoft_pkg/flexisoft_library.h>
#include <sick_flexisoft_pkg/flexisoft_define.h>
#include <sick_flexisoft_pkg/FlexSetStopOperationalSrv.h>
#include <sick_flexisoft_pkg/FlexSetZoneSrv.h>
#include <sick_flexisoft_pkg/FlexSetMuteReleaseSrv.h>
#include <sick_flexisoft_pkg/FlexSetPayloadSrv.h>
#include <sick_flexisoft_pkg/FlexSetMappingSrv.h>



clientSock *Flexisoft = new clientSock("10.147.20.68", 1100);

bool ServiceCbFlexSetStopOperationalSrv(sick_flexisoft_pkg::FlexSetStopOperationalSrv::Request  &req,
                                        sick_flexisoft_pkg::FlexSetStopOperationalSrv::Response &res)
{
  res.success = req.STOP_OPERATIONAL;
  
  ROS_INFO("sending back response: [%B]", res.success);
  return true;
} 
bool ServiceCbFlexSetZoneSrv(sick_flexisoft_pkg::FlexSetZoneSrv::Request  &req,
                                        sick_flexisoft_pkg::FlexSetZoneSrv::Response &res)
{
  res.success = req.STOP_OPERATIONAL;
  
  ROS_INFO("sending back response: [%B]", res.success);
  return true;
}
bool ServiceCbFlexSetMuteReleaseSrv(sick_flexisoft_pkg::FlexSetMuteReleaseSrv::Request  &req,
                                        sick_flexisoft_pkg::FlexSetMuteReleaseSrv::Response &res)
{
  res.success = req.STOP_OPERATIONAL;
  
  ROS_INFO("sending back response: [%B]", res.success);
  return true;
}
bool ServiceCbFlexSetPayloadSrv(sick_flexisoft_pkg::FlexSetPayloadSrv::Request  &req,
                                        sick_flexisoft_pkg::FlexSetPayloadSrv::Response &res)
{
  res.success = req.STOP_OPERATIONAL;
  
  ROS_INFO("sending back response: [%B]", res.success);
  return true;
}
bool ServiceCbFlexSetMappingSrv(sick_flexisoft_pkg::FlexSetMappingSrv::Request  &req,
                                        sick_flexisoft_pkg::FlexSetMappingSrv::Response &res)
{
  res.success = req.STOP_OPERATIONAL;
  
  ROS_INFO("sending back response: [%B]", res.success);
  return true;
}


int main(int argc, char **argv)
{

    ros::init(argc, argv, "safety_function");
    ros::NodeHandle nh;

    ros::ServiceServer Srv_FlexSetStopOperationalSrv = nh.advertiseService("FlexSetStopOperationalSrv", ServiceCbFlexSetStopOperationalSrv);
    ros::ServiceServer Srv_FlexSetZoneSrv = nh.advertiseService("FlexSetZoneSrv", ServiceCbFlexSetZoneSrv);
    ros::ServiceServer Srv_FlexSetMuteReleaseSrv = nh.advertiseService("FlexSetMuteReleaseSrv", ServiceCbFlexSetMuteReleaseSrv);
    ros::ServiceServer Srv_FlexSetPayloadSrv = nh.advertiseService("FlexSetPayloadSrv", ServiceCbFlexSetPayloadSrv);
    ros::ServiceServer Srv_FlexSetMappingSrv = nh.advertiseService("FlexSetMappingSrv", ServiceCbFlexSetMappingSrv);
   



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




  
