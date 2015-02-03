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

//#include <alljoyn.h>
//#include <alljoyn/controlpanel/Common/ConstraintList.h>
//#include <alljoyn/controlpanel/ControlPanelService.h>
//#include "ControlPanelProvided.h"

#include <alljoyn.h>
#include <ConstraintList.h>
#include <ControlPanelService.h>
#include "ControlPanelProvided.h"


#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

const char FurnitureHttpControlObjectPath[] = "/ControlPanel/Furniture/HTTPControl";
const char FurnitureFurnitureControllerObjectPath[] = "/ControlPanel/Furniture/FurnitureController";
const char enFurnitureFurnitureControllerObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en";
const char enFurnitureLedObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/led";
const char enFurnitureStartObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/start";
const char enFurnitureStopObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/stop";

ContainerWidget FurnitureFurnitureController;
PropertyWidget FurnitureLed;
ActionWidget FurnitureStart;
ActionWidget FurnitureStop;

/*
 * Static variables used to fill widgets
 */
static HttpControl FurnitureHttpControl;
static const char* FurnitureHttpControlUrl = "http://MyControlPanelUrl.com";
static const uint16_t FurnitureFurnitureControllerHints[] = { LAYOUT_HINT_VERTICAL_LINEAR };
static const char* const FurnitureLedSignature = "q";
static const char* const FurnitureLedLabel[] = { "Lamp" };
static const uint16_t FurnitureLedHints[] = { PROPERTY_WIDGET_HINT_SLIDER };
static const char* const FurnitureLedUnitMeasure[] = { "luminance" };
static const uint16_t FurnitureLedConstraintRangeMin = 0;
static const uint16_t FurnitureLedConstraintRangeMax = 10;
static const uint16_t FurnitureLedConstraintRangeInc = 1;
static const char* const FurnitureStartLabel[] = { "Start Buzzing" };
static const uint16_t FurnitureStartHints[] = { ACTION_WIDGET_HINT_ACTIONBUTTON };
static const char* const FurnitureStopLabel[] = { "Stop Buzzing" };
static const uint16_t FurnitureStopHints[] = { ACTION_WIDGET_HINT_ACTIONBUTTON };


void WidgetsInit()
{
    initializeHttpControl(&FurnitureHttpControl);
    FurnitureHttpControl.url = FurnitureHttpControlUrl;

    initializeContainerWidget(&FurnitureFurnitureController);
    FurnitureFurnitureController.base.numLanguages = 1;
    setBaseEnabled(&FurnitureFurnitureController.base, TRUE);

    FurnitureFurnitureController.base.optParams.bgColor = 0x200;
    FurnitureFurnitureController.base.optParams.hints = FurnitureFurnitureControllerHints;
    FurnitureFurnitureController.base.optParams.numHints = 1;

    initializePropertyWidget(&FurnitureLed);
    FurnitureLed.base.numLanguages = 1;
    setBaseEnabled(&FurnitureLed.base, TRUE);
    setBaseWritable(&FurnitureLed.base, TRUE);

    FurnitureLed.signature = FurnitureLedSignature;
    FurnitureLed.propertyType = SINGLE_VALUE_PROPERTY;
    FurnitureLed.getValue = &getuint16Var;

    FurnitureLed.base.optParams.bgColor = 0x500;
    FurnitureLed.base.optParams.label = FurnitureLedLabel;
    FurnitureLed.base.optParams.hints = FurnitureLedHints;
    FurnitureLed.base.optParams.numHints = 1;
    FurnitureLed.optParams.unitOfMeasure = FurnitureLedUnitMeasure;

    FurnitureLed.optParams.constraintRangeDefined = TRUE;
    FurnitureLed.optParams.constraintRange.minValue = &FurnitureLedConstraintRangeMin;
    FurnitureLed.optParams.constraintRange.maxValue = &FurnitureLedConstraintRangeMax;
    FurnitureLed.optParams.constraintRange.increment = &FurnitureLedConstraintRangeInc;

    initializeActionWidget(&FurnitureStart);
    FurnitureStart.base.numLanguages = 1;
    setBaseEnabled(&FurnitureStart.base, TRUE);

    FurnitureStart.base.optParams.bgColor = 0x400;
    FurnitureStart.base.optParams.label = FurnitureStartLabel;
    FurnitureStart.base.optParams.hints = FurnitureStartHints;
    FurnitureStart.base.optParams.numHints = 1;

    initializeActionWidget(&FurnitureStop);
    FurnitureStop.base.numLanguages = 1;
    setBaseEnabled(&FurnitureStop.base, TRUE);

    FurnitureStop.base.optParams.bgColor = 0x400;
    FurnitureStop.base.optParams.label = FurnitureStopLabel;
    FurnitureStop.base.optParams.hints = FurnitureStopHints;
    FurnitureStop.base.optParams.numHints = 1;

    return;
}

void* IdentifyMsgOrPropId(uint32_t identifier, uint16_t* widgetType, uint16_t* propType, uint16_t* language)
{
    switch (identifier) {
    case FURNITURE_HTTPCONTROL_GET_ROOT_URL:
        *widgetType = WIDGET_TYPE_HTTP;
        *propType = PROPERTY_TYPE_URL;
        return &FurnitureHttpControl;

    case EN_FURNITURE_FURNITURECONTROLLER_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureFurnitureController;

    case EN_FURNITURE_FURNITURECONTROLLER_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_VERSION;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureFurnitureController;

    case EN_FURNITURE_FURNITURECONTROLLER_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_STATES;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureFurnitureController;

    case EN_FURNITURE_FURNITURECONTROLLER_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_CONTAINER;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureFurnitureController;

    case EN_FURNITURE_LED_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureLed;

    case EN_FURNITURE_LED_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureLed;

    case EN_FURNITURE_LED_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureLed;

    case EN_FURNITURE_LED_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureLed;

    case EN_FURNITURE_LED_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureLed;

    case EN_FURNITURE_START_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_ACTION;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureStart;

    case EN_FURNITURE_START_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_VERSION;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureStart;

    case EN_FURNITURE_START_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_STATES;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureStart;

    case EN_FURNITURE_START_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureStart;

    case EN_FURNITURE_STOP_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_ACTION;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureStop;

    case EN_FURNITURE_STOP_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_VERSION;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureStop;

    case EN_FURNITURE_STOP_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_STATES;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureStop;

    case EN_FURNITURE_STOP_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_ACTION;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureStop;

    default:
        return FALSE;
    }
}

void* IdentifyMsgOrPropIdForSignal(uint32_t identifier, uint8_t* isProperty)
{
    switch (identifier) {
    case EN_FURNITURE_FURNITURECONTROLLER_SIGNAL_PROPERTIES_CHANGED:
        return &FurnitureFurnitureController;

    case EN_FURNITURE_LED_SIGNAL_PROPERTIES_CHANGED:
        return &FurnitureLed;

    case EN_FURNITURE_LED_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &FurnitureLed;

    case EN_FURNITURE_START_SIGNAL_PROPERTIES_CHANGED:
        return &FurnitureStart;

    case EN_FURNITURE_STOP_SIGNAL_PROPERTIES_CHANGED:
        return &FurnitureStop;

    default:
        return FALSE;
    }
}

uint8_t IdentifyRootMsgOrPropId(uint32_t identifier)
{
    switch (identifier) {
    case FURNITURE_HTTPCONTROL_GET_ALL_VALUES:
    case FURNITURE_HTTPCONTROL_VERSION_PROPERTY:
        return TRUE;

    case FURNITURE_ROOT_CONTROLPANEL_FURNITURECONTROLLER_VERSION_PROPERTY:
    case FURNITURE_ROOT_CONTROLPANEL_FURNITURECONTROLLER_GET_ALL_VALUES:
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
    case EN_FURNITURE_LED_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&FurnitureLed, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setuint16Var(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_FURNITURE_LED_SIGNAL_VALUE_CHANGED;
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
    case EN_FURNITURE_START_EXEC:
        {
            openBuzzing();
        }
        break;

    case EN_FURNITURE_STOP_EXEC:
        {
            closeBuzzing();
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
