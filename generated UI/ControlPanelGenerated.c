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

/**
 * Per-module definition of the current module for debug logging.  Must be defined
 * prior to first inclusion of aj_debug.h.
 * The corresponding flag dbgAJSVCAPP is defined in the containing sample app.
 */
#define AJ_MODULE AJSVCAPP
#include <aj_debug.h>

#include <alljoyn.h>
#include <alljoyn/controlpanel/Common/ConstraintList.h>
#include <alljoyn/controlpanel/ControlPanelService.h>
#include "ControlPanelProvided.h"

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

const char MyOvenHttpControlObjectPath[] = "/ControlPanel/MyOven/HTTPControl";
const char MyOvenOvenControllerObjectPath[] = "/ControlPanel/MyOven/OvenController";
const char enMyOvenOvenControllerObjectPath[] = "/ControlPanel/MyOven/OvenController/en";
const char enMyOvenProgramObjectPath[] = "/ControlPanel/MyOven/OvenController/en/program";
const char enMyOvenTemperatureObjectPath[] = "/ControlPanel/MyOven/OvenController/en/temperature";
const char enMyOvenStartObjectPath[] = "/ControlPanel/MyOven/OvenController/en/start";
const char enMyOvenStopObjectPath[] = "/ControlPanel/MyOven/OvenController/en/stop";

ContainerWidget MyOvenOvenController;
PropertyWidget MyOvenProgram;
PropertyWidget MyOvenTemperature;
ActionWidget MyOvenStart;
ActionWidget MyOvenStop;

/*
 * Static variables used to fill widgets
 */
static HttpControl MyOvenHttpControl;
static const char* MyOvenHttpControlUrl = "http://MyControlPanelUrl.com";
static const char* const MyOvenOvenControllerLabel[] = { "My kitchen Oven" };
static const uint16_t MyOvenOvenControllerHints[] = { LAYOUT_HINT_VERTICAL_LINEAR };
static const char* const MyOvenProgramSignature = "q";
static const uint16_t MyOvenProgramHints[] = { PROPERTY_WIDGET_HINT_RADIOBUTTON };
static ConstraintList MyOvenProgramConstraintList[4];
static const uint16_t MyOvenProgramConstraintValue0 = 0;
static const char* const MyOvenProgramDisplay0[] = { "Off" };
static const uint16_t MyOvenProgramConstraintValue1 = 1;
static const char* const MyOvenProgramDisplay1[] = { "Bake" };
static const uint16_t MyOvenProgramConstraintValue2 = 2;
static const char* const MyOvenProgramDisplay2[] = { "Broil" };
static const uint16_t MyOvenProgramConstraintValue3 = 3;
static const char* const MyOvenProgramDisplay3[] = { "Keep warm" };
static const char* const MyOvenTemperatureSignature = "q";
static const char* const MyOvenTemperatureLabel[] = { "Temperature" };
static const uint16_t MyOvenTemperatureHints[] = { PROPERTY_WIDGET_HINT_SLIDER };
static const char* const MyOvenTemperatureUnitMeasure[] = { "Fahrenheit" };
static const uint16_t MyOvenTemperatureConstraintRangeMin = 200;
static const uint16_t MyOvenTemperatureConstraintRangeMax = 500;
static const uint16_t MyOvenTemperatureConstraintRangeInc = 20;
static const char* const MyOvenStartLabel[] = { "Start" };
static const uint16_t MyOvenStartHints[] = { ACTION_WIDGET_HINT_ACTIONBUTTON };
static const char* const MyOvenStopLabel[] = { "Stop" };
static const uint16_t MyOvenStopHints[] = { ACTION_WIDGET_HINT_ACTIONBUTTON };


void WidgetsInit()
{
    initializeHttpControl(&MyOvenHttpControl);
    MyOvenHttpControl.url = MyOvenHttpControlUrl;

    initializeContainerWidget(&MyOvenOvenController);
    MyOvenOvenController.base.numLanguages = 1;
    setBaseEnabled(&MyOvenOvenController.base, TRUE);

    MyOvenOvenController.base.optParams.bgColor = 0x200;
    MyOvenOvenController.base.optParams.label = MyOvenOvenControllerLabel;
    MyOvenOvenController.base.optParams.hints = MyOvenOvenControllerHints;
    MyOvenOvenController.base.optParams.numHints = 1;

    initializePropertyWidget(&MyOvenProgram);
    MyOvenProgram.base.numLanguages = 1;
    setBaseEnabled(&MyOvenProgram.base, TRUE);
    setBaseWritable(&MyOvenProgram.base, TRUE);

    MyOvenProgram.signature = MyOvenProgramSignature;
    MyOvenProgram.propertyType = SINGLE_VALUE_PROPERTY;
    MyOvenProgram.getValue = &getProgram;

    MyOvenProgram.base.optParams.bgColor = 0x500;
    MyOvenProgram.base.optParams.getLabel = getProgramString;
    MyOvenProgram.base.optParams.hints = MyOvenProgramHints;
    MyOvenProgram.base.optParams.numHints = 1;

    MyOvenProgram.optParams.numConstraints = 4;
    MyOvenProgram.optParams.constraintList = MyOvenProgramConstraintList;
    MyOvenProgram.optParams.constraintList[0].value = &MyOvenProgramConstraintValue0;
    MyOvenProgram.optParams.constraintList[0].display = MyOvenProgramDisplay0;
    MyOvenProgram.optParams.constraintList[1].value = &MyOvenProgramConstraintValue1;
    MyOvenProgram.optParams.constraintList[1].display = MyOvenProgramDisplay1;
    MyOvenProgram.optParams.constraintList[2].value = &MyOvenProgramConstraintValue2;
    MyOvenProgram.optParams.constraintList[2].display = MyOvenProgramDisplay2;
    MyOvenProgram.optParams.constraintList[3].value = &MyOvenProgramConstraintValue3;
    MyOvenProgram.optParams.constraintList[3].display = MyOvenProgramDisplay3;

    initializePropertyWidget(&MyOvenTemperature);
    MyOvenTemperature.base.numLanguages = 1;
    setBaseEnabled(&MyOvenTemperature.base, TRUE);
    setBaseWritable(&MyOvenTemperature.base, TRUE);

    MyOvenTemperature.signature = MyOvenTemperatureSignature;
    MyOvenTemperature.propertyType = SINGLE_VALUE_PROPERTY;
    MyOvenTemperature.getValue = &getTemperature;

    MyOvenTemperature.base.optParams.bgColor = 0x500;
    MyOvenTemperature.base.optParams.label = MyOvenTemperatureLabel;
    MyOvenTemperature.base.optParams.hints = MyOvenTemperatureHints;
    MyOvenTemperature.base.optParams.numHints = 1;
    MyOvenTemperature.optParams.unitOfMeasure = MyOvenTemperatureUnitMeasure;

    MyOvenTemperature.optParams.constraintRangeDefined = TRUE;
    MyOvenTemperature.optParams.constraintRange.minValue = &MyOvenTemperatureConstraintRangeMin;
    MyOvenTemperature.optParams.constraintRange.maxValue = &MyOvenTemperatureConstraintRangeMax;
    MyOvenTemperature.optParams.constraintRange.increment = &MyOvenTemperatureConstraintRangeInc;

    initializeActionWidget(&MyOvenStart);
    MyOvenStart.base.numLanguages = 1;
    setBaseEnabled(&MyOvenStart.base, TRUE);

    MyOvenStart.base.optParams.bgColor = 0x400;
    MyOvenStart.base.optParams.label = MyOvenStartLabel;
    MyOvenStart.base.optParams.hints = MyOvenStartHints;
    MyOvenStart.base.optParams.numHints = 1;

    initializeActionWidget(&MyOvenStop);
    MyOvenStop.base.numLanguages = 1;
    setBaseEnabled(&MyOvenStop.base, TRUE);

    MyOvenStop.base.optParams.bgColor = 0x400;
    MyOvenStop.base.optParams.label = MyOvenStopLabel;
    MyOvenStop.base.optParams.hints = MyOvenStopHints;
    MyOvenStop.base.optParams.numHints = 1;

    return;
}

void* IdentifyMsgOrPropId(uint32_t identifier, uint16_t* widgetType, uint16_t* propType, uint16_t* language)
{
    switch (identifier) {
    case MYOVEN_HTTPCONTROL_GET_ROOT_URL:
        *widgetType = WIDGET_TYPE_HTTP;
        *propType = PROPERTY_TYPE_URL;
        return &MyOvenHttpControl;

    case EN_MYOVEN_OVENCONTROLLER_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenOvenController;

    case EN_MYOVEN_OVENCONTROLLER_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_VERSION;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenOvenController;

    case EN_MYOVEN_OVENCONTROLLER_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_STATES;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenOvenController;

    case EN_MYOVEN_OVENCONTROLLER_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenOvenController;

    case EN_MYOVEN_PROGRAM_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenProgram;

    case EN_MYOVEN_PROGRAM_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenProgram;

    case EN_MYOVEN_PROGRAM_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenProgram;

    case EN_MYOVEN_PROGRAM_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenProgram;

    case EN_MYOVEN_PROGRAM_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenProgram;

    case EN_MYOVEN_TEMPERATURE_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenTemperature;

    case EN_MYOVEN_TEMPERATURE_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenTemperature;

    case EN_MYOVEN_TEMPERATURE_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenTemperature;

    case EN_MYOVEN_TEMPERATURE_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenTemperature;

    case EN_MYOVEN_TEMPERATURE_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenTemperature;

    case EN_MYOVEN_START_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_ACTION;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenStart;

    case EN_MYOVEN_START_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_VERSION;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenStart;

    case EN_MYOVEN_START_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_STATES;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenStart;

    case EN_MYOVEN_START_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenStart;

    case EN_MYOVEN_STOP_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_ACTION;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenStop;

    case EN_MYOVEN_STOP_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_VERSION;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenStop;

    case EN_MYOVEN_STOP_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_STATES;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenStop;

    case EN_MYOVEN_STOP_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = MYOVEN_MYLANGUAGES_EN;
        return &MyOvenStop;

    default:
        return FALSE;
    }
}

void* IdentifyMsgOrPropIdForSignal(uint32_t identifier, uint8_t* isProperty)
{
    switch (identifier) {
    case EN_MYOVEN_OVENCONTROLLER_SIGNAL_PROPERTIES_CHANGED:
        return &MyOvenOvenController;

    case EN_MYOVEN_PROGRAM_SIGNAL_PROPERTIES_CHANGED:
        return &MyOvenProgram;

    case EN_MYOVEN_PROGRAM_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &MyOvenProgram;

    case EN_MYOVEN_TEMPERATURE_SIGNAL_PROPERTIES_CHANGED:
        return &MyOvenTemperature;

    case EN_MYOVEN_TEMPERATURE_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &MyOvenTemperature;

    case EN_MYOVEN_START_SIGNAL_PROPERTIES_CHANGED:
        return &MyOvenStart;

    case EN_MYOVEN_STOP_SIGNAL_PROPERTIES_CHANGED:
        return &MyOvenStop;

    default:
        return FALSE;
    }
}

uint8_t IdentifyRootMsgOrPropId(uint32_t identifier)
{
    switch (identifier) {
    case MYOVEN_HTTPCONTROL_GET_ALL_VALUES:
    case MYOVEN_HTTPCONTROL_VERSION_PROPERTY:
        return TRUE;

    case MYOVEN_ROOT_CONTROLPANEL_OVENCONTROLLER_VERSION_PROPERTY:
    case MYOVEN_ROOT_CONTROLPANEL_OVENCONTROLLER_GET_ALL_VALUES:
        return TRUE;

    default:
        return FALSE;
    }
}

AJ_Status SetValueProperty(AJ_Message* replyMsg, uint32_t propId, void* context)
{
    AJ_Status status = AJ_ERR_UNEXPECTED;

    const char* variantSig;
    AJ_UnmarshalVariant(replyMsg, &variantSig);

    switch (propId) {
    case EN_MYOVEN_PROGRAM_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&MyOvenProgram, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setProgram(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_MYOVEN_PROGRAM_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_MYOVEN_TEMPERATURE_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&MyOvenTemperature, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setTemperature(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_MYOVEN_TEMPERATURE_SIGNAL_VALUE_CHANGED;
        }
        break;


    }

    return status;
}

AJ_Status ExecuteAction(AJ_Message* msg, uint32_t msgId, ExecuteActionContext* context)
{
    AJ_Message reply;
    AJ_MarshalReplyMsg(msg, &reply);

    switch (msgId) {
    case EN_MYOVEN_START_EXEC:
        {
            startOven();
        }
        break;

    case EN_MYOVEN_STOP_EXEC:
        {
            stopOven();
        }
        break;


    }

    return AJ_DeliverMsg(&reply);
}

void TestsInit(CPSTest* testsToRun)
{

}

AJSVC_ServiceStatus GeneratedMessageProcessor(AJ_BusAttachment* bus, AJ_Message* msg, AJ_Status* msgStatus)
{
    AJSVC_ServiceStatus AJSVC_ServiceStatus = AJSVC_SERVICE_STATUS_HANDLED;

    switch (msg->msgId) {
        GET_WIDGET_VALUE_CASES
        *msgStatus = AJ_BusPropGet(msg, AJCPS_GetWidgetProperty, NULL);
        break;

        GET_WIDGET_ALL_VALUE_CASES
        *msgStatus = AJCPS_GetAllWidgetProperties(msg, msg->msgId);
        break;

        GET_ROOT_VALUE_CASES
        *msgStatus = AJ_BusPropGet(msg, AJCPS_GetRootProperty, NULL);
        break;

        GET_ROOT_ALL_VALUE_CASES
        *msgStatus = AJCPS_GetAllRootProperties(msg, msg->msgId);
        break;

        SET_VALUE_CASES
        {
            SetValueContext context;
            context.sender = msg->sender;
            context.numSignals = 0;
            *msgStatus = AJ_BusPropSet(msg, SetValueProperty, &context);
            if (*msgStatus == AJ_OK && context.numSignals != 0) {
                uint16_t indx;
                for (indx = 0; indx < context.numSignals; indx++) {
                    *msgStatus = AJCPS_SendPropertyChangedSignal(bus, context.signals[indx], AJCPS_GetCurrentSessionId());
                }
            }
        }
        break;

        ACTION_CASES
        {
            ExecuteActionContext context;
            context.numSignals = 0;
            *msgStatus = ExecuteAction(msg, msg->msgId, &context);
            if (*msgStatus == AJ_OK && context.numSignals != 0) {
                uint16_t indx;
                for (indx = 0; indx < context.numSignals; indx++) {
                    if (context.signals[indx].signalType == SIGNAL_TYPE_DATA_CHANGED) {
                        *msgStatus = AJCPS_SendPropertyChangedSignal(bus, context.signals[indx].signalId, AJCPS_GetCurrentSessionId());
                    } else if (context.signals[indx].signalType == SIGNAL_TYPE_DISMISS) {
                        *msgStatus = AJCPS_SendDismissSignal(bus, context.signals[indx].signalId, AJCPS_GetCurrentSessionId());
                    }
                }
            }
        }
        break;

        GET_URL_CASES
        *msgStatus = AJCPS_SendRootUrl(msg, msg->msgId);
        break;

    case AJ_SIGNAL_SESSION_LOST:
        break;

    default:
        AJSVC_ServiceStatus = AJSVC_SERVICE_STATUS_NOT_HANDLED;
        break;
    }

    return AJSVC_ServiceStatus;
}
