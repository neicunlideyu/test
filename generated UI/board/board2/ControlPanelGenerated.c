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

const char FurnitureHttpControlObjectPath[] = "/ControlPanel/Furniture/HTTPControl";
const char FurnitureFurnitureControllerObjectPath[] = "/ControlPanel/Furniture/FurnitureController";
const char enFurnitureFurnitureControllerObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en";
const char enFurnitureLightObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/light";
const char enFurnitureElectric_fanObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/electric_fan";

ContainerWidget FurnitureFurnitureController;
PropertyWidget FurnitureLight;
PropertyWidget FurnitureElectric_fan;

/*
 * Static variables used to fill widgets
 */
static HttpControl FurnitureHttpControl;
static const char* FurnitureHttpControlUrl = "http://MyControlPanelUrl.com";
static const uint16_t FurnitureFurnitureControllerHints[] = { LAYOUT_HINT_VERTICAL_LINEAR };
static const char* const FurnitureLightSignature = "q";
static const char* const FurnitureLightLabel[] = { "Electric Fan" };
static const uint16_t FurnitureLightHints[] = { PROPERTY_WIDGET_HINT_RADIOBUTTON };
static ConstraintList FurnitureLightConstraintList[4];
static const uint16_t FurnitureLightConstraintValue0 = 0;
static const char* const FurnitureLightDisplay0[] = { "Off" };
static const uint16_t FurnitureLightConstraintValue1 = 1;
static const char* const FurnitureLightDisplay1[] = { "On" };
static const uint16_t FurnitureLightConstraintValue2 = 2;
static const char* const FurnitureLightDisplay2[] = { "Flash 1" };
static const uint16_t FurnitureLightConstraintValue3 = 3;
static const char* const FurnitureLightDisplay3[] = { "Flash 2" };
static const char* const FurnitureElectric_fanSignature = "q";
static const char* const FurnitureElectric_fanLabel[] = { "electric_fan" };
static const uint16_t FurnitureElectric_fanHints[] = { PROPERTY_WIDGET_HINT_SLIDER };
static const char* const FurnitureElectric_fanUnitMeasure[] = { "intensity" };
static const uint16_t FurnitureElectric_fanConstraintRangeMin = 0;
static const uint16_t FurnitureElectric_fanConstraintRangeMax = 4;
static const uint16_t FurnitureElectric_fanConstraintRangeInc = 1;


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

    initializePropertyWidget(&FurnitureLight);
    FurnitureLight.base.numLanguages = 1;
    setBaseEnabled(&FurnitureLight.base, TRUE);
    setBaseWritable(&FurnitureLight.base, TRUE);

    FurnitureLight.signature = FurnitureLightSignature;
    FurnitureLight.propertyType = SINGLE_VALUE_PROPERTY;
    FurnitureLight.getValue = &getProgram;

    FurnitureLight.base.optParams.bgColor = 0x500;
    FurnitureLight.base.optParams.label = FurnitureLightLabel;
    FurnitureLight.base.optParams.hints = FurnitureLightHints;
    FurnitureLight.base.optParams.numHints = 1;

    FurnitureLight.optParams.numConstraints = 4;
    FurnitureLight.optParams.constraintList = FurnitureLightConstraintList;
    FurnitureLight.optParams.constraintList[0].value = &FurnitureLightConstraintValue0;
    FurnitureLight.optParams.constraintList[0].display = FurnitureLightDisplay0;
    FurnitureLight.optParams.constraintList[1].value = &FurnitureLightConstraintValue1;
    FurnitureLight.optParams.constraintList[1].display = FurnitureLightDisplay1;
    FurnitureLight.optParams.constraintList[2].value = &FurnitureLightConstraintValue2;
    FurnitureLight.optParams.constraintList[2].display = FurnitureLightDisplay2;
    FurnitureLight.optParams.constraintList[3].value = &FurnitureLightConstraintValue3;
    FurnitureLight.optParams.constraintList[3].display = FurnitureLightDisplay3;

    initializePropertyWidget(&FurnitureElectric_fan);
    FurnitureElectric_fan.base.numLanguages = 1;
    setBaseEnabled(&FurnitureElectric_fan.base, TRUE);
    setBaseWritable(&FurnitureElectric_fan.base, TRUE);

    FurnitureElectric_fan.signature = FurnitureElectric_fanSignature;
    FurnitureElectric_fan.propertyType = SINGLE_VALUE_PROPERTY;
    FurnitureElectric_fan.getValue = &getuint32Var;

    FurnitureElectric_fan.base.optParams.bgColor = 0x500;
    FurnitureElectric_fan.base.optParams.label = FurnitureElectric_fanLabel;
    FurnitureElectric_fan.base.optParams.hints = FurnitureElectric_fanHints;
    FurnitureElectric_fan.base.optParams.numHints = 1;
    FurnitureElectric_fan.optParams.unitOfMeasure = FurnitureElectric_fanUnitMeasure;

    FurnitureElectric_fan.optParams.constraintRangeDefined = TRUE;
    FurnitureElectric_fan.optParams.constraintRange.minValue = &FurnitureElectric_fanConstraintRangeMin;
    FurnitureElectric_fan.optParams.constraintRange.maxValue = &FurnitureElectric_fanConstraintRangeMax;
    FurnitureElectric_fan.optParams.constraintRange.increment = &FurnitureElectric_fanConstraintRangeInc;

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

    case EN_FURNITURE_LIGHT_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureLight;

    case EN_FURNITURE_LIGHT_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureLight;

    case EN_FURNITURE_LIGHT_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureLight;

    case EN_FURNITURE_LIGHT_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureLight;

    case EN_FURNITURE_LIGHT_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureLight;

    case EN_FURNITURE_ELECTRIC_FAN_GET_ALL_VALUES:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureElectric_fan;

    case EN_FURNITURE_ELECTRIC_FAN_VERSION_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VERSION;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureElectric_fan;

    case EN_FURNITURE_ELECTRIC_FAN_STATES_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_STATES;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureElectric_fan;

    case EN_FURNITURE_ELECTRIC_FAN_OPTPARAMS_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_OPTPARAMS;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureElectric_fan;

    case EN_FURNITURE_ELECTRIC_FAN_VALUE_PROPERTY:
        *widgetType = WIDGET_TYPE_PROPERTY;
        *propType = PROPERTY_TYPE_VALUE;
        *language = FURNITURE_MYLANGUAGES_EN;
        return &FurnitureElectric_fan;

    default:
        return FALSE;
    }
}

void* IdentifyMsgOrPropIdForSignal(uint32_t identifier, uint8_t* isProperty)
{
    switch (identifier) {
    case EN_FURNITURE_FURNITURECONTROLLER_SIGNAL_PROPERTIES_CHANGED:
        return &FurnitureFurnitureController;

    case EN_FURNITURE_LIGHT_SIGNAL_PROPERTIES_CHANGED:
        return &FurnitureLight;

    case EN_FURNITURE_LIGHT_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &FurnitureLight;

    case EN_FURNITURE_ELECTRIC_FAN_SIGNAL_PROPERTIES_CHANGED:
        return &FurnitureElectric_fan;

    case EN_FURNITURE_ELECTRIC_FAN_SIGNAL_VALUE_CHANGED:
        *isProperty = TRUE;
        return &FurnitureElectric_fan;

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
    case EN_FURNITURE_LIGHT_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&FurnitureLight, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setProgram(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_FURNITURE_LIGHT_SIGNAL_VALUE_CHANGED;
        }
        break;

    case EN_FURNITURE_ELECTRIC_FAN_VALUE_PROPERTY:
        {
            uint16_t newValue;
            status = unmarshalPropertyValue(&FurnitureElectric_fan, replyMsg, &newValue, ((SetValueContext*)context)->sender);
            if (status != AJ_OK) {
                return status;
            }
            setuint32Var(newValue);
            ((SetValueContext*)context)->numSignals = 1;
            ((SetValueContext*)context)->signals[0] = EN_FURNITURE_ELECTRIC_FAN_SIGNAL_VALUE_CHANGED;
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
