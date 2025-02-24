
"use strict";

let RadarDetections = require('./RadarDetections.js');
let SkateboardCtrlCmd = require('./SkateboardCtrlCmd.js');
let WoowaDillyStatus = require('./WoowaDillyStatus.js');
let SVADC = require('./SVADC.js');
let MoraiSimProcStatus = require('./MoraiSimProcStatus.js');
let DdCtrlCmd = require('./DdCtrlCmd.js');
let VehicleSpec = require('./VehicleSpec.js');
let MultiPlayEventRequest = require('./MultiPlayEventRequest.js');
let ScenarioLoad = require('./ScenarioLoad.js');
let SensorPosControl = require('./SensorPosControl.js');
let FaultStatusInfo_Vehicle = require('./FaultStatusInfo_Vehicle.js');
let PRStatus = require('./PRStatus.js');
let GPSMessage = require('./GPSMessage.js');
let ObjectStatusExtended = require('./ObjectStatusExtended.js');
let ERP42Info = require('./ERP42Info.js');
let WaitForTick = require('./WaitForTick.js');
let RadarDetection = require('./RadarDetection.js');
let SyncModeScenarioLoad = require('./SyncModeScenarioLoad.js');
let ObjectStatusListExtended = require('./ObjectStatusListExtended.js');
let ReplayInfo = require('./ReplayInfo.js');
let MoraiTLIndex = require('./MoraiTLIndex.js');
let CollisionData = require('./CollisionData.js');
let EventInfo = require('./EventInfo.js');
let PRCtrlCmd = require('./PRCtrlCmd.js');
let NpcGhostCmd = require('./NpcGhostCmd.js');
let Lamps = require('./Lamps.js');
let VehicleSpecIndex = require('./VehicleSpecIndex.js');
let MapSpecIndex = require('./MapSpecIndex.js');
let FaultStatusInfo = require('./FaultStatusInfo.js');
let SkidSteer6wUGVStatus = require('./SkidSteer6wUGVStatus.js');
let IntscnTL = require('./IntscnTL.js');
let FaultInjection_Response = require('./FaultInjection_Response.js');
let CtrlCmd = require('./CtrlCmd.js');
let SaveSensorData = require('./SaveSensorData.js');
let SyncModeCmdResponse = require('./SyncModeCmdResponse.js');
let MultiEgoSetting = require('./MultiEgoSetting.js');
let SyncModeInfo = require('./SyncModeInfo.js');
let FaultInjection_Controller = require('./FaultInjection_Controller.js');
let SyncModeAddObject = require('./SyncModeAddObject.js');
let SkateboardStatus = require('./SkateboardStatus.js');
let DillyCmd = require('./DillyCmd.js');
let SetTrafficLight = require('./SetTrafficLight.js');
let GetTrafficLightStatus = require('./GetTrafficLightStatus.js');
let MoraiSrvResponse = require('./MoraiSrvResponse.js');
let SyncModeResultResponse = require('./SyncModeResultResponse.js');
let MoraiTLInfo = require('./MoraiTLInfo.js');
let FaultInjection_Tire = require('./FaultInjection_Tire.js');
let EgoDdVehicleStatus = require('./EgoDdVehicleStatus.js');
let SyncModeCmd = require('./SyncModeCmd.js');
let MoraiSimProcHandle = require('./MoraiSimProcHandle.js');
let SyncModeCtrlCmd = require('./SyncModeCtrlCmd.js');
let EgoVehicleStatusExtended = require('./EgoVehicleStatusExtended.js');
let DillyCmdResponse = require('./DillyCmdResponse.js');
let MapSpec = require('./MapSpec.js');
let SyncModeSetGear = require('./SyncModeSetGear.js');
let VehicleCollisionData = require('./VehicleCollisionData.js');
let SkidSteer6wUGVCtrlCmd = require('./SkidSteer6wUGVCtrlCmd.js');
let NpcGhostInfo = require('./NpcGhostInfo.js');
let ObjectStatusList = require('./ObjectStatusList.js');
let PREvent = require('./PREvent.js');
let SyncModeRemoveObject = require('./SyncModeRemoveObject.js');
let WaitForTickResponse = require('./WaitForTickResponse.js');
let MultiPlayEventResponse = require('./MultiPlayEventResponse.js');
let FaultInjection_Sensor = require('./FaultInjection_Sensor.js');
let TrafficLight = require('./TrafficLight.js');
let FaultStatusInfo_Sensor = require('./FaultStatusInfo_Sensor.js');
let IntersectionControl = require('./IntersectionControl.js');
let GhostMessage = require('./GhostMessage.js');
let ObjectStatus = require('./ObjectStatus.js');
let FaultStatusInfo_Overall = require('./FaultStatusInfo_Overall.js');
let EgoVehicleStatus = require('./EgoVehicleStatus.js');
let IntersectionStatus = require('./IntersectionStatus.js');
let VehicleCollision = require('./VehicleCollision.js');

module.exports = {
  RadarDetections: RadarDetections,
  SkateboardCtrlCmd: SkateboardCtrlCmd,
  WoowaDillyStatus: WoowaDillyStatus,
  SVADC: SVADC,
  MoraiSimProcStatus: MoraiSimProcStatus,
  DdCtrlCmd: DdCtrlCmd,
  VehicleSpec: VehicleSpec,
  MultiPlayEventRequest: MultiPlayEventRequest,
  ScenarioLoad: ScenarioLoad,
  SensorPosControl: SensorPosControl,
  FaultStatusInfo_Vehicle: FaultStatusInfo_Vehicle,
  PRStatus: PRStatus,
  GPSMessage: GPSMessage,
  ObjectStatusExtended: ObjectStatusExtended,
  ERP42Info: ERP42Info,
  WaitForTick: WaitForTick,
  RadarDetection: RadarDetection,
  SyncModeScenarioLoad: SyncModeScenarioLoad,
  ObjectStatusListExtended: ObjectStatusListExtended,
  ReplayInfo: ReplayInfo,
  MoraiTLIndex: MoraiTLIndex,
  CollisionData: CollisionData,
  EventInfo: EventInfo,
  PRCtrlCmd: PRCtrlCmd,
  NpcGhostCmd: NpcGhostCmd,
  Lamps: Lamps,
  VehicleSpecIndex: VehicleSpecIndex,
  MapSpecIndex: MapSpecIndex,
  FaultStatusInfo: FaultStatusInfo,
  SkidSteer6wUGVStatus: SkidSteer6wUGVStatus,
  IntscnTL: IntscnTL,
  FaultInjection_Response: FaultInjection_Response,
  CtrlCmd: CtrlCmd,
  SaveSensorData: SaveSensorData,
  SyncModeCmdResponse: SyncModeCmdResponse,
  MultiEgoSetting: MultiEgoSetting,
  SyncModeInfo: SyncModeInfo,
  FaultInjection_Controller: FaultInjection_Controller,
  SyncModeAddObject: SyncModeAddObject,
  SkateboardStatus: SkateboardStatus,
  DillyCmd: DillyCmd,
  SetTrafficLight: SetTrafficLight,
  GetTrafficLightStatus: GetTrafficLightStatus,
  MoraiSrvResponse: MoraiSrvResponse,
  SyncModeResultResponse: SyncModeResultResponse,
  MoraiTLInfo: MoraiTLInfo,
  FaultInjection_Tire: FaultInjection_Tire,
  EgoDdVehicleStatus: EgoDdVehicleStatus,
  SyncModeCmd: SyncModeCmd,
  MoraiSimProcHandle: MoraiSimProcHandle,
  SyncModeCtrlCmd: SyncModeCtrlCmd,
  EgoVehicleStatusExtended: EgoVehicleStatusExtended,
  DillyCmdResponse: DillyCmdResponse,
  MapSpec: MapSpec,
  SyncModeSetGear: SyncModeSetGear,
  VehicleCollisionData: VehicleCollisionData,
  SkidSteer6wUGVCtrlCmd: SkidSteer6wUGVCtrlCmd,
  NpcGhostInfo: NpcGhostInfo,
  ObjectStatusList: ObjectStatusList,
  PREvent: PREvent,
  SyncModeRemoveObject: SyncModeRemoveObject,
  WaitForTickResponse: WaitForTickResponse,
  MultiPlayEventResponse: MultiPlayEventResponse,
  FaultInjection_Sensor: FaultInjection_Sensor,
  TrafficLight: TrafficLight,
  FaultStatusInfo_Sensor: FaultStatusInfo_Sensor,
  IntersectionControl: IntersectionControl,
  GhostMessage: GhostMessage,
  ObjectStatus: ObjectStatus,
  FaultStatusInfo_Overall: FaultStatusInfo_Overall,
  EgoVehicleStatus: EgoVehicleStatus,
  IntersectionStatus: IntersectionStatus,
  VehicleCollision: VehicleCollision,
};
