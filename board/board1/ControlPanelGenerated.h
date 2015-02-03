/******************************************************************************
 * Copyright (c) 2013 - 2014, AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#ifndef CONTROL_GENERATED_H_
#define CONTROL_GENERATED_H_

#include <alljoyn.h>
#include <alljoyn/controlpanel/Widgets/ActionWidget.h>
#include <alljoyn/controlpanel/Widgets/PropertyWidget.h>
#include <alljoyn/controlpanel/Widgets/ContainerWidget.h>
#include <alljoyn/controlpanel/Widgets/LabelWidget.h>
#include <alljoyn/controlpanel/Widgets/DialogWidget.h>
#include <alljoyn/controlpanel/Common/HttpControl.h>
#include <alljoyn/services_common/Services_Common.h>

/**
 * Defines and objectPaths
 */
#define NUM_PRECEDING_OBJECTS NUM_PRE_CONTROLPANEL_OBJECTS

#define GET_WIDGET_VALUE_CASES \
case EN_FURNITURE_FURNITURECONTROLLER_GET_VALUE: \
case EN_FURNITURE_LED_GET_VALUE: \
case EN_FURNITURE_START_GET_VALUE: \
case EN_FURNITURE_STOP_GET_VALUE: \


#define GET_WIDGET_ALL_VALUE_CASES \
case EN_FURNITURE_FURNITURECONTROLLER_GET_ALL_VALUES: \
case EN_FURNITURE_LED_GET_ALL_VALUES: \
case EN_FURNITURE_START_GET_ALL_VALUES: \
case EN_FURNITURE_STOP_GET_ALL_VALUES: \


#define GET_ROOT_VALUE_CASES \
case FURNITURE_HTTPCONTROL_GET_VALUE:\
case FURNITURE_ROOT_CONTROLPANEL_FURNITURECONTROLLER_GET_VALUE: \


#define GET_ROOT_ALL_VALUE_CASES \
case FURNITURE_HTTPCONTROL_GET_ALL_VALUES:\
case FURNITURE_ROOT_CONTROLPANEL_FURNITURECONTROLLER_GET_ALL_VALUES: \


#define SET_VALUE_CASES \
case FURNITURE_HTTPCONTROL_SET_VALUE:\
case FURNITURE_ROOT_CONTROLPANEL_FURNITURECONTROLLER_SET_VALUE: \
case EN_FURNITURE_FURNITURECONTROLLER_SET_VALUE: \
case EN_FURNITURE_LED_SET_VALUE: \
case EN_FURNITURE_START_SET_VALUE: \
case EN_FURNITURE_STOP_SET_VALUE: \


#define ACTION_CASES \
case EN_FURNITURE_START_EXEC: \
case EN_FURNITURE_STOP_EXEC: \


#define GET_URL_CASES \
case FURNITURE_HTTPCONTROL_GET_ROOT_URL:\


#define CONTROLPANELAPPOBJECTS     {  FurnitureHttpControlObjectPath, HttpControlInterfaces  }, \
    {  FurnitureFurnitureControllerObjectPath, ControlPanelInterfaces  }, \
    {  enFurnitureFurnitureControllerObjectPath, ContainerInterfaces  }, \
    {  enFurnitureLedObjectPath, PropertyInterfaces  }, \
    {  enFurnitureStartObjectPath, ActionInterfaces  }, \
    {  enFurnitureStopObjectPath, ActionInterfaces  }, \


#define CONTROLPANELANNOUNCEOBJECTS     {  FurnitureHttpControlObjectPath, HttpControlInterfaces  }, \
    {  FurnitureFurnitureControllerObjectPath, ControlPanelInterfaces  }, \


#define MAX_NUM_LANGUAGES 1

#define NUM_CONTROLPANEL_OBJECTS 6

#define FURNITURE_MYLANGUAGES_EN 0

#define FURNITURE_HTTPCONTROL_GET_VALUE             AJ_APP_MESSAGE_ID(0 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define FURNITURE_HTTPCONTROL_SET_VALUE             AJ_APP_MESSAGE_ID(0 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define FURNITURE_HTTPCONTROL_GET_ALL_VALUES        AJ_APP_MESSAGE_ID(0 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define FURNITURE_HTTPCONTROL_VERSION_PROPERTY      AJ_APP_PROPERTY_ID(0 + NUM_PRECEDING_OBJECTS, 1, 0)
#define FURNITURE_HTTPCONTROL_GET_ROOT_URL          AJ_APP_MESSAGE_ID(0 + NUM_PRECEDING_OBJECTS, 1, 1)

#define FURNITURE_ROOT_CONTROLPANEL_FURNITURECONTROLLER_GET_VALUE                  AJ_APP_MESSAGE_ID(1 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define FURNITURE_ROOT_CONTROLPANEL_FURNITURECONTROLLER_SET_VALUE                  AJ_APP_MESSAGE_ID(1 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define FURNITURE_ROOT_CONTROLPANEL_FURNITURECONTROLLER_GET_ALL_VALUES             AJ_APP_MESSAGE_ID(1 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define FURNITURE_ROOT_CONTROLPANEL_FURNITURECONTROLLER_VERSION_PROPERTY           AJ_APP_PROPERTY_ID(1 + NUM_PRECEDING_OBJECTS, 1, 0)

#define EN_FURNITURE_FURNITURECONTROLLER_GET_VALUE                  AJ_APP_MESSAGE_ID(2 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_FURNITURE_FURNITURECONTROLLER_SET_VALUE                  AJ_APP_MESSAGE_ID(2 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_FURNITURE_FURNITURECONTROLLER_GET_ALL_VALUES             AJ_APP_MESSAGE_ID(2 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_FURNITURE_FURNITURECONTROLLER_VERSION_PROPERTY           AJ_APP_PROPERTY_ID(2 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_FURNITURE_FURNITURECONTROLLER_STATES_PROPERTY            AJ_APP_PROPERTY_ID(2 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_FURNITURE_FURNITURECONTROLLER_OPTPARAMS_PROPERTY         AJ_APP_PROPERTY_ID(2 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_FURNITURE_FURNITURECONTROLLER_SIGNAL_PROPERTIES_CHANGED  AJ_APP_MESSAGE_ID(2 + NUM_PRECEDING_OBJECTS, 1, 3)

#define EN_FURNITURE_LED_GET_VALUE                  AJ_APP_MESSAGE_ID(3 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_FURNITURE_LED_SET_VALUE                  AJ_APP_MESSAGE_ID(3 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_FURNITURE_LED_GET_ALL_VALUES             AJ_APP_MESSAGE_ID(3 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_FURNITURE_LED_VERSION_PROPERTY           AJ_APP_PROPERTY_ID(3 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_FURNITURE_LED_STATES_PROPERTY            AJ_APP_PROPERTY_ID(3 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_FURNITURE_LED_OPTPARAMS_PROPERTY         AJ_APP_PROPERTY_ID(3 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_FURNITURE_LED_SIGNAL_PROPERTIES_CHANGED  AJ_APP_MESSAGE_ID(3 + NUM_PRECEDING_OBJECTS, 1, 3)
#define EN_FURNITURE_LED_VALUE_PROPERTY             AJ_APP_PROPERTY_ID(3 + NUM_PRECEDING_OBJECTS, 1, 4)
#define EN_FURNITURE_LED_SIGNAL_VALUE_CHANGED       AJ_APP_MESSAGE_ID(3 + NUM_PRECEDING_OBJECTS, 1, 5)

#define EN_FURNITURE_START_GET_VALUE                  AJ_APP_MESSAGE_ID(4 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_FURNITURE_START_SET_VALUE                  AJ_APP_MESSAGE_ID(4 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_FURNITURE_START_GET_ALL_VALUES             AJ_APP_MESSAGE_ID(4 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_FURNITURE_START_VERSION_PROPERTY           AJ_APP_PROPERTY_ID(4 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_FURNITURE_START_STATES_PROPERTY            AJ_APP_PROPERTY_ID(4 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_FURNITURE_START_OPTPARAMS_PROPERTY         AJ_APP_PROPERTY_ID(4 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_FURNITURE_START_SIGNAL_PROPERTIES_CHANGED  AJ_APP_MESSAGE_ID(4 + NUM_PRECEDING_OBJECTS, 1, 3)
#define EN_FURNITURE_START_EXEC                       AJ_APP_MESSAGE_ID(4 + NUM_PRECEDING_OBJECTS, 1, 4)

#define EN_FURNITURE_STOP_GET_VALUE                  AJ_APP_MESSAGE_ID(5 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_FURNITURE_STOP_SET_VALUE                  AJ_APP_MESSAGE_ID(5 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_FURNITURE_STOP_GET_ALL_VALUES             AJ_APP_MESSAGE_ID(5 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_FURNITURE_STOP_VERSION_PROPERTY           AJ_APP_PROPERTY_ID(5 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_FURNITURE_STOP_STATES_PROPERTY            AJ_APP_PROPERTY_ID(5 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_FURNITURE_STOP_OPTPARAMS_PROPERTY         AJ_APP_PROPERTY_ID(5 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_FURNITURE_STOP_SIGNAL_PROPERTIES_CHANGED  AJ_APP_MESSAGE_ID(5 + NUM_PRECEDING_OBJECTS, 1, 3)
#define EN_FURNITURE_STOP_EXEC                       AJ_APP_MESSAGE_ID(5 + NUM_PRECEDING_OBJECTS, 1, 4)



extern const char FurnitureHttpControlObjectPath[];
extern const char FurnitureFurnitureControllerObjectPath[];
extern const char enFurnitureFurnitureControllerObjectPath[];
extern const char enFurnitureLedObjectPath[];
extern const char enFurnitureStartObjectPath[];
extern const char enFurnitureStopObjectPath[];


extern ContainerWidget FurnitureFurnitureController;
extern PropertyWidget FurnitureLed;
extern ActionWidget FurnitureStart;
extern ActionWidget FurnitureStop;


typedef struct {
    const char* sender;
    uint16_t numSignals;
    int32_t signals[MAX_NUM_LANGUAGES];
} SetValueContext;

typedef struct {
    uint8_t signalType;
    int32_t signalId;
} Signal;

typedef struct {
    uint16_t numSignals;
    Signal signals[MAX_NUM_LANGUAGES * 2];
} ExecuteActionContext;
/**
 *
 * @return
 */
void WidgetsInit();

/**
 * Set Value of a property.
 * @param replyMsg - reply message
 * @param propId - id of property being changed
 * @param context - setvaluecontext. can be used to send signals
 * @return status
 */
AJ_Status SetValueProperty(AJ_Message* replyMsg, uint32_t propId, void* context);

/**
 * Execute Action
 * @param msg - the msg for the response
 * @param msgId - the Action being executed
 * @param context - ExecuteActionContext used to send signals as a result of action
 * @return status
 */
AJ_Status ExecuteAction(AJ_Message* msg, uint32_t msgId, ExecuteActionContext* context);


/* Defines and functions for Tester App */
typedef struct {
    uint32_t msgId;
    uint16_t numParams;
    uint16_t param[3];
} CPSTest;

#define NUMBER_OF_TESTS //NUM_TESTS_GO_HERE

#define ALL_REPLY_CASES                //ALL_REPLIES_GO_HERE

void TestsInit(CPSTest* testsToRun);

void* IdentifyMsgOrPropId(uint32_t identifier, uint16_t* widgetType, uint16_t* propType, uint16_t* language);
void* IdentifyMsgOrPropIdForSignal(uint32_t identifier, uint8_t* isProperty);
uint8_t IdentifyRootMsgOrPropId(uint32_t identifier);
AJSVC_ServiceStatus GeneratedMessageProcessor(AJ_BusAttachment* bus, AJ_Message* msg, AJ_Status* msgStatus);

#endif /* CONTROL_GENERATED_H_ */
