#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <configure.h>
#include <Types.hpp>

namespace PROGRAM_NAMESPACE {

constexpr double EPSILON = 2.0;

namespace settings {

// variabili configurazione cambridge technology (CT)
static constexpr char CT_REFRESH_INTERVAL_MS[] = "Cambridge/RefreshTimeMs";
static constexpr char CT_RESTART_INTERVAL_MS[] = "Cambridge/RestartTimeMs";
static constexpr char CT_BROADCAST_IP_ADDRESS[] = "Cambridge/BroadcastIpAddress";
static constexpr char CT_BROADCAST_PORT[] = "Cambridge/BroadcastPort";
static constexpr char CT_SETUP_SOCKET_IP_ADDRESS[] = "Cambridge/SetupSocketIpAddress";
static constexpr char CT_SETUP_SOCKET_PORT[] = "Cambridge/SetupSocketPort";

static constexpr quint16 CT_REFRESH_INTERVAL_MS_DFLT = 100;
static constexpr quint16 CT_RESTART_INTERVAL_MS_DFLT = 5000;
static constexpr char CT_BROADCAST_IP_ADDRESS_DFLT[] = "224.168.100.2";
static constexpr quint16 CT_BROADCAST_PORT_DFLT = 11000;
static constexpr char CT_SETUP_SOCKET_IP_ADDRESS_DFLT[] = "192.168.100.20";
static constexpr quint16 CT_SETUP_SOCKET_PORT_DFLT = 49000;

// variabili di macchina
static constexpr char MACHINE_LOCAL_IP_ADDRESS[] = "Machine/LocalIpAddress";
static constexpr char MACHINE_LOCAL_IP_ADDRESS_DFLT[] = "192.168.100.2";

static constexpr char SMC_CONF_CUTHEIGHT[] = "SmcConf/CutHeight";
static constexpr char SMC_CONF_XSTART[] = "SmcConf/XStart";
static constexpr char SMC_CONF_YSTART[] = "SmcConf/YStart";
static constexpr char SMC_CONF_LASERDUTY[] = "SmcConf/LaserDuty";
static constexpr char SMC_CONF_LASERJUMPSPEED[] = "SmcConf/LaserJumpSpeed";
static constexpr char SMC_CONF_LASERMARKSPEED[] = "SmcConf/LaserMarkSpeed";
static constexpr char SMC_CONF_LASERMARKDELAY[] = "SmcConf/LaserMarkDelay";
static constexpr char SMC_CONF_LASERJUMPDELAY[] = "SmcConf/LaserJumpDelay";
static constexpr char SMC_CONF_LASERPOLYDELAY[] = "SmcConf/LaserPolyDelay";
static constexpr char SMC_CONF_LASERONDELAY[] = "SmcConf/LaserOnDelay";
static constexpr char SMC_CONF_LASEROFFDELAY[] = "SmcConf/LaserOffDelay";
static constexpr char SMC_CONF_LASERPIPELINEDELAY[] = "SmcConf/LaserPipelineDelay";
static constexpr char SMC_CONF_ENCODERPULSES[] = "SmcConf/EncoderPulses";

}


// variabili di cambridge
static constexpr char CT_STATUS_XPOSACK[] = "XPosAck";
static constexpr char CT_STATUS_YPOSACK[] = "YPosAck";
static constexpr char CT_STATUS_XPOS[] = "XPos";
static constexpr char CT_STATUS_YPOS[] = "YPos";
static constexpr char CT_STATUS_XACTPOS[] = "XActPos";
static constexpr char CT_STATUS_YACTPOS[] = "YActPos";
static constexpr char CT_STATUS_XTEMP[] = "XTemp";
static constexpr char CT_STATUS_YTEMP[] = "YTemp";
static constexpr char CT_STATUS_CONTRLTEMP[] = "ContrlTemp";
static constexpr char CT_STATUS_XSTATUS[] = "XStatus";
static constexpr char CT_STATUS_YSTATUS[] = "YStatus";
static constexpr char CT_STATUS_XPOWER[] = "XPower";
static constexpr char CT_STATUS_YPOWER[] = "YPower";
static constexpr char CT_STATUS_INTERLOCK[] = "Interlock";
static constexpr char CT_STATUS_CURRENTDIO[] = "CurrentDIO";
static constexpr char CT_STATUS_JOBMARKER[] = "JobMarker";
static constexpr char CT_STATUS_JOBDATACNTR[] = "JobDataCntr";

static constexpr char CT_SYSTEM_MSN[] = "MSN";
static constexpr char CT_SYSTEM_PVER[] = "PVer";
static constexpr char CT_SYSTEM_AVER[] = "AVer";
static constexpr char CT_SYSTEM_OBJEXTVER[] = "ObjExtVer";
static constexpr char CT_SYSTEM_FPGAFIRMVER[] = "FPGAFirmVer";
static constexpr char CT_SYSTEM_STATECODE[] = "StateCode";
static constexpr char CT_SYSTEM_LASTERROR[] = "LastError";
static constexpr char CT_SYSTEM_FREETEMPSTORAGE[] = "FreeTempStorage";
static constexpr char CT_SYSTEM_PERMSTORAGEPATH[] = "PermStoragePath";
static constexpr char CT_SYSTEM_FREEPERMSTORAGE[] = "FreePermStorage";
static constexpr char CT_SYSTEM_FREEUSBSTORAGE[] = "FreeUSBStorage";
static constexpr char CT_SYSTEM_MAC[] = "MAC";
static constexpr char CT_SYSTEM_NETMASK[] = "NetMask";
static constexpr char CT_SYSTEM_NETASSIGN[] = "NetAssign";
static constexpr char CT_SYSTEM_IP[] = "IP";
static constexpr char CT_SYSTEM_CONNECTIP[] = "ConnectIP";
static constexpr char CT_SYSTEM_FRIENDLYNAME[] = "FriendlyName";
static constexpr char CT_SYSTEM_CONNECTJOB[] = "ConnectJob";
static constexpr char CT_SYSTEM_PORT[] = "Port";
static constexpr char CT_SYSTEM_HSN[] = "HSN";

}

#endif // CONSTANTS_HPP
