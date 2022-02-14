#include <sick_flexisoft_pkg/flexisoft_library.h>
#include <sick_flexisoft_pkg/flexisoft_define.h>
#include <sick_flexisoft_pkg/FlexSetStopOperationalSrv.h>
#include <sick_flexisoft_pkg/FlexSetZoneSrv.h>
#include <sick_flexisoft_pkg/FlexSetMuteReleaseSrv.h>
#include <sick_flexisoft_pkg/FlexSetPayloadSrv.h>
#include <sick_flexisoft_pkg/FlexSetMappingSrv.h>

clientSock *Flexisoft = new clientSock("10.147.20.100", 1100);

bool ServiceCbFlexSetStopOperationalSrv(sick_flexisoft_pkg::FlexSetStopOperationalSrv::Request &req,
                                        sick_flexisoft_pkg::FlexSetStopOperationalSrv::Response &res)
{
for (size_t i = 0; i < 4; i++)
    {
        Flexisoft->flex_write_bit(IPC_STOP_OPERATIONAL_RELEASE, req.STOP_OPERATIONAL);
        if ((Flexisoft->flex_read_bit(FX3_SAF_STOP_OPERATIONAL)) == req.STOP_OPERATIONAL)
        {
        res.success = true;
        ROS_INFO(" ");
        ROS_INFO("sending back response: [%x]",Flexisoft->flex_read_bit(FX3_SAF_STOP_OPERATIONAL));
        ROS_INFO(" FlexSetStopOperationalSrv done");
        return true;
        }
  
    }
        res.success = false;
        ROS_INFO("FlexSetStopOperationalSrv false");
        return true;    
}
bool ServiceCbFlexSetZoneSrv(sick_flexisoft_pkg::FlexSetZoneSrv::Request &req,
                             sick_flexisoft_pkg::FlexSetZoneSrv::Response &res)
{
for (size_t i = 0; i < 4; i++)
    {
        Flexisoft->flex_write_bit(IPC_STOP_OPERATIONAL_RELEASE, req.STOP_OPERATIONAL);
        if ((Flexisoft->flex_read_bit(FX3_SAF_STOP_OPERATIONAL)) == req.STOP_OPERATIONAL)
        {
        res.success = true;
        ROS_INFO(" ");
        ROS_INFO("sending back response: [%x]",Flexisoft->flex_read_bit(FX3_SAF_STOP_OPERATIONAL));
        ROS_INFO(" FlexSetStopOperationalSrv done");
        return true;
        }
  
    }
        res.success = false;
        ROS_INFO("FlexSetStopOperationalSrv false");
        return true;
}
bool ServiceCbFlexSetMuteReleaseSrv(sick_flexisoft_pkg::FlexSetMuteReleaseSrv::Request &req,
                                    sick_flexisoft_pkg::FlexSetMuteReleaseSrv::Response &res)
{
for (size_t i = 0; i < 4; i++)
    {
        Flexisoft->flex_write_bit(IPC_SAF_MUTE_RELEASE, req.MUTE_RELEASE);
        if ((Flexisoft->flex_read_bit(FX3_SAF_MUTE_RELEASE)) == req.MUTE_RELEASE)
        {
        res.success = true;
        ROS_INFO(" ");
        ROS_INFO("sending back response: [%x]",Flexisoft->flex_read_bit(FX3_SAF_MUTE_RELEASE));
        ROS_INFO(" FlexSetMuteReleaseSrv done");
        return true;
        }
  
    }
        res.success = false;
        ROS_INFO("FlexSetMuteReleaseSrv false");
        return true;
}
bool ServiceCbFlexSetPayloadSrv(sick_flexisoft_pkg::FlexSetPayloadSrv::Request &req,
                                sick_flexisoft_pkg::FlexSetPayloadSrv::Response &res)
{
for (size_t i = 0; i < 4; i++)
    {
        Flexisoft->flex_write_bit(IPC_SAF_PAYLOAD_RELEASE, req.PAYLOAD_RELEASE);
        if ((Flexisoft->flex_read_bit(FX3_SAF_PAYLOAD_RELEASE)) == req.PAYLOAD_RELEASE)
        {
        res.success = true;
        ROS_INFO(" ");
        ROS_INFO("sending back response: [%x]",Flexisoft->flex_read_bit(FX3_SAF_PAYLOAD_RELEASE));
        ROS_INFO(" FlexSetPayloadSrv done");
        return true;
        }
  
    }
        res.success = false;
        ROS_INFO("FlexSetStopOperationalSrv false");
        return true;
}
bool ServiceCbFlexSetMappingSrv(sick_flexisoft_pkg::FlexSetMappingSrv::Request &req,
                                sick_flexisoft_pkg::FlexSetMappingSrv::Response &res)
{
for (size_t i = 0; i < 4; i++)
    {
        Flexisoft->flex_write_bit(IPC_SAF_MAPPING_RELEASE, req.MAPPING_RELEASE);
        if ((Flexisoft->flex_read_bit(FX3_SAF_MAPPING_RELEASE)) == req.MAPPING_RELEASE)
        {
        res.success = true;
        ROS_INFO(" ");
        ROS_INFO("sending back response: [%x]",Flexisoft->flex_read_bit(FX3_SAF_MAPPING_RELEASE));
        ROS_INFO(" FlexSetMappingSrv done");
        return true;
        }
  
    }
        res.success = false;
        ROS_INFO("FlexSetMappingSrv false");
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

    // sick_flexisoft_pkg::SAFE_SP_AGV SAFE_SP_AGV;

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

            // Flexisoft->tcp_read(DATA_SET_01);

            // Flexisoft->tcp_write_all();
            //  sleep(1);
            //  cout << "running" << endl;
            //  ROS_INFO("FLEXISOFT IS RUNNING......");
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
