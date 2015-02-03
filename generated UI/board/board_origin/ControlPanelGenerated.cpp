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
const char enFurnitureElectric_FanObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/Electric_Fan";
const char enFurnitureLedObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/led";
const char enFurnitureStartObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/start";
const char enFurnitureStopObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/stop";
const char enFurnitureLampObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/lamp";
const char enFurnitureLightConfirmObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/lamp/LightConfirm";
const char enFurnitureCurrentTempObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/CurrentTemp";
const char enFurnitureModeStringPropertyObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/modeStringProperty";
const char enFurnitureCheckboxPropertyObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/checkboxProperty";
const char enFurnitureStartDatePropertyObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/startDateProperty";
const char enFurnitureStartTimePropertyObjectPath[] = "/ControlPanel/Furniture/FurnitureController/en/startTimeProperty";

ContainerWidget FurnitureFurnitureController;
PropertyWidget FurnitureElectric_Fan;
PropertyWidget FurnitureLed;
ActionWidget FurnitureStart;
ActionWidget FurnitureStop;
ActionWidget FurnitureLamp;
DialogWidget FurnitureLightConfirm;
LabelWidget FurnitureCurrentTemp;
PropertyWidget FurnitureModeStringProperty;
PropertyWidget FurnitureCheckboxProperty;
PropertyWidget FurnitureStartDateProperty;
PropertyWidget FurnitureStartTimeProperty;

/*
* Static variables used to fill widgets
*/
static HttpControl FurnitureHttpControl;
static const char* FurnitureHttpControlUrl = "http://MyControlPanelUrl.com";
static const uint16_t FurnitureFurnitureControllerHints[] = { LAYOUT_HINT_VERTICAL_LINEAR };
static const char* const FurnitureElectric_FanSignature = "q";
static const char* const FurnitureElectric_FanLabel[] = { "Electric Fan" };
static const uint16_t FurnitureElectric_FanHints[] = { PROPERTY_WIDGET_HINT_RADIOBUTTON };
static ConstraintList FurnitureElectric_FanConstraintList[2];
static const uint16_t FurnitureElectric_FanConstraintValue0 = 0;
static const char* const FurnitureElectric_FanDisplay0[] = { "Off" };
static const uint16_t FurnitureElectric_FanConstraintValue1 = 1;
static const char* const FurnitureElectric_FanDisplay1[] = { "On" };
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
static const char* const FurnitureLampLabel[] = { "Lamp" };
static const uint16_t FurnitureLampHints[] = { ACTION_WIDGET_HINT_ACTIONBUTTON };
static const char* const FurnitureLightConfirmMessage[] = { "Do you want to turn on the light" };
static const char* const FurnitureLightConfirmLabel[] = { "Turn on Light" };
static const uint16_t FurnitureLightConfirmHints[] = { DIALOG_HINT_ALERTDIALOG };
static const char* const FurnitureLightConfirmLabelaction1[] = { "Yes" };
static const char* const FurnitureLightConfirmLabelaction2[] = { "No" };
static const char* const FurnitureCurrentTempLabel[] = { "Current Temperature:" };
static const uint16_t FurnitureCurrentTempHints[] = { LABEL_HINT_TEXTLABEL };
static const char* const FurnitureModeStringPropertySignature = "s";
static const uint16_t FurnitureModeStringPropertyHints[] = { PROPERTY_WIDGET_HINT_EDITTEXT };
static const char* const FurnitureCheckboxPropertySignature = "b";
static const char* const FurnitureCheckboxPropertyLabel[] = { "Turbo Mode:" };
static const uint16_t FurnitureCheckboxPropertyHints[] = { PROPERTY_WIDGET_HINT_CHECKBOX };
static const char* const FurnitureStartDatePropertyLabel[] = { "Start Date:" };
static const uint16_t FurnitureStartDatePropertyHints[] = { PROPERTY_WIDGET_HINT_DATEPICKER };
static const char* const FurnitureStartTimePropertyLabel[] = { "Start Time:" };
static const uint16_t FurnitureStartTimePropertyHints[] = { PROPERTY_WIDGET_HINT_TIMEPICKER };


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

	initializePropertyWidget(&FurnitureElectric_Fan);
	FurnitureElectric_Fan.base.numLanguages = 1;
	setBaseEnabled(&FurnitureElectric_Fan.base, TRUE);
	setBaseWritable(&FurnitureElectric_Fan.base, TRUE);

	FurnitureElectric_Fan.signature = FurnitureElectric_FanSignature;
	FurnitureElectric_Fan.propertyType = SINGLE_VALUE_PROPERTY;
	FurnitureElectric_Fan.getValue = &getProgram;

	FurnitureElectric_Fan.base.optParams.bgColor = 0x500;
	FurnitureElectric_Fan.base.optParams.label = FurnitureElectric_FanLabel;
	FurnitureElectric_Fan.base.optParams.hints = FurnitureElectric_FanHints;
	FurnitureElectric_Fan.base.optParams.numHints = 1;

	FurnitureElectric_Fan.optParams.numConstraints = 2;
	FurnitureElectric_Fan.optParams.constraintList = FurnitureElectric_FanConstraintList;
	FurnitureElectric_Fan.optParams.constraintList[0].value = &FurnitureElectric_FanConstraintValue0;
	FurnitureElectric_Fan.optParams.constraintList[0].display = FurnitureElectric_FanDisplay0;
	FurnitureElectric_Fan.optParams.constraintList[1].value = &FurnitureElectric_FanConstraintValue1;
	FurnitureElectric_Fan.optParams.constraintList[1].display = FurnitureElectric_FanDisplay1;

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

	initializeActionWidget(&FurnitureLamp);
	FurnitureLamp.base.numLanguages = 1;
	setBaseEnabled(&FurnitureLamp.base, TRUE);

	FurnitureLamp.base.optParams.bgColor = 0x400;
	FurnitureLamp.base.optParams.label = FurnitureLampLabel;
	FurnitureLamp.base.optParams.hints = FurnitureLampHints;
	FurnitureLamp.base.optParams.numHints = 1;
	initializeDialogWidget(&FurnitureLightConfirm);
	FurnitureLightConfirm.base.numLanguages = 1;
	setBaseEnabled(&FurnitureLightConfirm.base, TRUE);
	FurnitureLightConfirm.message = FurnitureLightConfirmMessage;
	FurnitureLightConfirm.numActions = 2;

	FurnitureLightConfirm.base.optParams.bgColor = 0x122;
	FurnitureLightConfirm.base.optParams.label = FurnitureLightConfirmLabel;
	FurnitureLightConfirm.base.optParams.hints = FurnitureLightConfirmHints;
	FurnitureLightConfirm.base.optParams.numHints = 1;
	FurnitureLightConfirm.optParams.labelAction1 = FurnitureLightConfirmLabelaction1;
	FurnitureLightConfirm.optParams.labelAction2 = FurnitureLightConfirmLabelaction2;

	initializeLabelWidget(&FurnitureCurrentTemp);
	FurnitureCurrentTemp.base.numLanguages = 1;
	setBaseEnabled(&FurnitureCurrentTemp.base, TRUE);
	FurnitureCurrentTemp.label = FurnitureCurrentTempLabel;

	FurnitureCurrentTemp.base.optParams.bgColor = 0x98765;
	FurnitureCurrentTemp.base.optParams.hints = FurnitureCurrentTempHints;
	FurnitureCurrentTemp.base.optParams.numHints = 1;

	initializePropertyWidget(&FurnitureModeStringProperty);
	FurnitureModeStringProperty.base.numLanguages = 1;
	setBaseEnabled(&FurnitureModeStringProperty.base, TRUE);
	setBaseWritable(&FurnitureModeStringProperty.base, TRUE);

	FurnitureModeStringProperty.signature = FurnitureModeStringPropertySignature;
	FurnitureModeStringProperty.propertyType = SINGLE_VALUE_PROPERTY;
	FurnitureModeStringProperty.getValue = &getStringVar;

	FurnitureModeStringProperty.base.optParams.bgColor = 0x500;
	FurnitureModeStringProperty.base.optParams.hints = FurnitureModeStringPropertyHints;
	FurnitureModeStringProperty.base.optParams.numHints = 1;

	initializePropertyWidget(&FurnitureCheckboxProperty);
	FurnitureCheckboxProperty.base.numLanguages = 1;
	setBaseEnabled(&FurnitureCheckboxProperty.base, TRUE);
	setBaseWritable(&FurnitureCheckboxProperty.base, TRUE);

	FurnitureCheckboxProperty.signature = FurnitureCheckboxPropertySignature;
	FurnitureCheckboxProperty.propertyType = SINGLE_VALUE_PROPERTY;
	FurnitureCheckboxProperty.getValue = &getboolVar;

	FurnitureCheckboxProperty.base.optParams.bgColor = 0x500;
	FurnitureCheckboxProperty.base.optParams.label = FurnitureCheckboxPropertyLabel;
	FurnitureCheckboxProperty.base.optParams.hints = FurnitureCheckboxPropertyHints;
	FurnitureCheckboxProperty.base.optParams.numHints = 1;

	initializePropertyWidget(&FurnitureStartDateProperty);
	FurnitureStartDateProperty.base.numLanguages = 1;
	setBaseEnabled(&FurnitureStartDateProperty.base, TRUE);
	setBaseWritable(&FurnitureStartDateProperty.base, TRUE);
	FurnitureStartDateProperty.propertyType = DATE_VALUE_PROPERTY;
	FurnitureStartDateProperty.getValue = &getDateProperty;

	FurnitureStartDateProperty.base.optParams.bgColor = 0x500;
	FurnitureStartDateProperty.base.optParams.label = FurnitureStartDatePropertyLabel;
	FurnitureStartDateProperty.base.optParams.hints = FurnitureStartDatePropertyHints;
	FurnitureStartDateProperty.base.optParams.numHints = 1;

	initializePropertyWidget(&FurnitureStartTimeProperty);
	FurnitureStartTimeProperty.base.numLanguages = 1;
	setBaseEnabled(&FurnitureStartTimeProperty.base, TRUE);
	setBaseWritable(&FurnitureStartTimeProperty.base, TRUE);
	FurnitureStartTimeProperty.propertyType = TIME_VALUE_PROPERTY;
	FurnitureStartTimeProperty.getValue = &getTimeProperty;

	FurnitureStartTimeProperty.base.optParams.bgColor = 0x500;
	FurnitureStartTimeProperty.base.optParams.label = FurnitureStartTimePropertyLabel;
	FurnitureStartTimeProperty.base.optParams.hints = FurnitureStartTimePropertyHints;
	FurnitureStartTimeProperty.base.optParams.numHints = 1;

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

	case EN_FURNITURE_ELECTRIC_FAN_GET_ALL_VALUES:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureElectric_Fan;

	case EN_FURNITURE_ELECTRIC_FAN_VERSION_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_VERSION;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureElectric_Fan;

	case EN_FURNITURE_ELECTRIC_FAN_STATES_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_STATES;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureElectric_Fan;

	case EN_FURNITURE_ELECTRIC_FAN_OPTPARAMS_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_OPTPARAMS;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureElectric_Fan;

	case EN_FURNITURE_ELECTRIC_FAN_VALUE_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_VALUE;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureElectric_Fan;

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

	case EN_FURNITURE_LAMP_GET_ALL_VALUES:
		*widgetType = WIDGET_TYPE_ACTION;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureLamp;

	case EN_FURNITURE_LAMP_VERSION_PROPERTY:
		*widgetType = WIDGET_TYPE_ACTION;
		*propType = PROPERTY_TYPE_VERSION;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureLamp;

	case EN_FURNITURE_LAMP_STATES_PROPERTY:
		*widgetType = WIDGET_TYPE_ACTION;
		*propType = PROPERTY_TYPE_STATES;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureLamp;

	case EN_FURNITURE_LAMP_OPTPARAMS_PROPERTY:
		*widgetType = WIDGET_TYPE_ACTION;
		*propType = PROPERTY_TYPE_OPTPARAMS;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureLamp;

	case EN_FURNITURE_LIGHTCONFIRM_GET_ALL_VALUES:
		*widgetType = WIDGET_TYPE_DIALOG;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureLightConfirm;

	case EN_FURNITURE_LIGHTCONFIRM_VERSION_PROPERTY:
		*widgetType = WIDGET_TYPE_DIALOG;
		*propType = PROPERTY_TYPE_VERSION;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureLightConfirm;

	case EN_FURNITURE_LIGHTCONFIRM_STATES_PROPERTY:
		*widgetType = WIDGET_TYPE_DIALOG;
		*propType = PROPERTY_TYPE_STATES;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureLightConfirm;

	case EN_FURNITURE_LIGHTCONFIRM_OPTPARAMS_PROPERTY:
		*widgetType = WIDGET_TYPE_DIALOG;
		*propType = PROPERTY_TYPE_OPTPARAMS;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureLightConfirm;

	case EN_FURNITURE_CURRENTTEMP_GET_ALL_VALUES:
		*widgetType = WIDGET_TYPE_LABEL;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureCurrentTemp;

	case EN_FURNITURE_CURRENTTEMP_VERSION_PROPERTY:
		*widgetType = WIDGET_TYPE_LABEL;
		*propType = PROPERTY_TYPE_VERSION;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureCurrentTemp;

	case EN_FURNITURE_CURRENTTEMP_STATES_PROPERTY:
		*widgetType = WIDGET_TYPE_LABEL;
		*propType = PROPERTY_TYPE_STATES;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureCurrentTemp;

	case EN_FURNITURE_CURRENTTEMP_OPTPARAMS_PROPERTY:
		*widgetType = WIDGET_TYPE_LABEL;
		*propType = PROPERTY_TYPE_OPTPARAMS;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureCurrentTemp;

	case EN_FURNITURE_CURRENTTEMP_LABEL_PROPERTY:
		*widgetType = WIDGET_TYPE_LABEL;
		*propType = PROPERTY_TYPE_LABEL;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureCurrentTemp;

	case EN_FURNITURE_MODESTRINGPROPERTY_GET_ALL_VALUES:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureModeStringProperty;

	case EN_FURNITURE_MODESTRINGPROPERTY_VERSION_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_VERSION;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureModeStringProperty;

	case EN_FURNITURE_MODESTRINGPROPERTY_STATES_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_STATES;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureModeStringProperty;

	case EN_FURNITURE_MODESTRINGPROPERTY_OPTPARAMS_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_OPTPARAMS;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureModeStringProperty;

	case EN_FURNITURE_MODESTRINGPROPERTY_VALUE_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_VALUE;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureModeStringProperty;

	case EN_FURNITURE_CHECKBOXPROPERTY_GET_ALL_VALUES:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureCheckboxProperty;

	case EN_FURNITURE_CHECKBOXPROPERTY_VERSION_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_VERSION;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureCheckboxProperty;

	case EN_FURNITURE_CHECKBOXPROPERTY_STATES_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_STATES;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureCheckboxProperty;

	case EN_FURNITURE_CHECKBOXPROPERTY_OPTPARAMS_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_OPTPARAMS;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureCheckboxProperty;

	case EN_FURNITURE_CHECKBOXPROPERTY_VALUE_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_VALUE;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureCheckboxProperty;

	case EN_FURNITURE_STARTDATEPROPERTY_GET_ALL_VALUES:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureStartDateProperty;

	case EN_FURNITURE_STARTDATEPROPERTY_VERSION_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_VERSION;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureStartDateProperty;

	case EN_FURNITURE_STARTDATEPROPERTY_STATES_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_STATES;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureStartDateProperty;

	case EN_FURNITURE_STARTDATEPROPERTY_OPTPARAMS_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_OPTPARAMS;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureStartDateProperty;

	case EN_FURNITURE_STARTDATEPROPERTY_VALUE_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_VALUE;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureStartDateProperty;

	case EN_FURNITURE_STARTTIMEPROPERTY_GET_ALL_VALUES:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureStartTimeProperty;

	case EN_FURNITURE_STARTTIMEPROPERTY_VERSION_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_VERSION;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureStartTimeProperty;

	case EN_FURNITURE_STARTTIMEPROPERTY_STATES_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_STATES;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureStartTimeProperty;

	case EN_FURNITURE_STARTTIMEPROPERTY_OPTPARAMS_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_OPTPARAMS;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureStartTimeProperty;

	case EN_FURNITURE_STARTTIMEPROPERTY_VALUE_PROPERTY:
		*widgetType = WIDGET_TYPE_PROPERTY;
		*propType = PROPERTY_TYPE_VALUE;
		*language = FURNITURE_MYLANGUAGES_EN;
		return &FurnitureStartTimeProperty;

	default:
		return FALSE;
	}
}

void* IdentifyMsgOrPropIdForSignal(uint32_t identifier, uint8_t* isProperty)
{
	switch (identifier) {
	case EN_FURNITURE_FURNITURECONTROLLER_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureFurnitureController;

	case EN_FURNITURE_ELECTRIC_FAN_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureElectric_Fan;

	case EN_FURNITURE_ELECTRIC_FAN_SIGNAL_VALUE_CHANGED:
		*isProperty = TRUE;
		return &FurnitureElectric_Fan;

	case EN_FURNITURE_LED_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureLed;

	case EN_FURNITURE_LED_SIGNAL_VALUE_CHANGED:
		*isProperty = TRUE;
		return &FurnitureLed;

	case EN_FURNITURE_START_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureStart;

	case EN_FURNITURE_STOP_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureStop;

	case EN_FURNITURE_LAMP_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureLamp;

	case EN_FURNITURE_LIGHTCONFIRM_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureLightConfirm;

	case EN_FURNITURE_CURRENTTEMP_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureCurrentTemp;

	case EN_FURNITURE_MODESTRINGPROPERTY_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureModeStringProperty;

	case EN_FURNITURE_MODESTRINGPROPERTY_SIGNAL_VALUE_CHANGED:
		*isProperty = TRUE;
		return &FurnitureModeStringProperty;

	case EN_FURNITURE_CHECKBOXPROPERTY_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureCheckboxProperty;

	case EN_FURNITURE_CHECKBOXPROPERTY_SIGNAL_VALUE_CHANGED:
		*isProperty = TRUE;
		return &FurnitureCheckboxProperty;

	case EN_FURNITURE_STARTDATEPROPERTY_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureStartDateProperty;

	case EN_FURNITURE_STARTDATEPROPERTY_SIGNAL_VALUE_CHANGED:
		*isProperty = TRUE;
		return &FurnitureStartDateProperty;

	case EN_FURNITURE_STARTTIMEPROPERTY_SIGNAL_PROPERTIES_CHANGED:
		return &FurnitureStartTimeProperty;

	case EN_FURNITURE_STARTTIMEPROPERTY_SIGNAL_VALUE_CHANGED:
		*isProperty = TRUE;
		return &FurnitureStartTimeProperty;

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
	case EN_FURNITURE_ELECTRIC_FAN_VALUE_PROPERTY:
	{
		uint16_t newValue;
		status = unmarshalPropertyValue(&FurnitureElectric_Fan, replyMsg, &newValue, ((SetValueContext*)context)->sender);
		if (status != AJ_OK) {
			return status;
		}
		setProgram(newValue);
		((SetValueContext*)context)->numSignals = 1;
		((SetValueContext*)context)->signals[0] = EN_FURNITURE_ELECTRIC_FAN_SIGNAL_VALUE_CHANGED;
	}
	break;

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

	case EN_FURNITURE_MODESTRINGPROPERTY_VALUE_PROPERTY:
	{
		const char* newValue;
		status = unmarshalPropertyValue(&FurnitureModeStringProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
		if (status != AJ_OK) {
			return status;
		}
		setStringVar(newValue);
		((SetValueContext*)context)->numSignals = 1;
		((SetValueContext*)context)->signals[0] = EN_FURNITURE_MODESTRINGPROPERTY_SIGNAL_VALUE_CHANGED;
	}
	break;

	case EN_FURNITURE_CHECKBOXPROPERTY_VALUE_PROPERTY:
	{
		uint32_t newValue;
		status = unmarshalPropertyValue(&FurnitureCheckboxProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
		if (status != AJ_OK) {
			return status;
		}
		setboolVar(newValue);
		((SetValueContext*)context)->numSignals = 1;
		((SetValueContext*)context)->signals[0] = EN_FURNITURE_CHECKBOXPROPERTY_SIGNAL_VALUE_CHANGED;
	}
	break;

	case EN_FURNITURE_STARTDATEPROPERTY_VALUE_PROPERTY:
	{
		DatePropertyValue newValue;
		status = unmarshalPropertyValue(&FurnitureStartDateProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
		if (status != AJ_OK) {
			return status;
		}
		setDateProperty(&newValue);
		((SetValueContext*)context)->numSignals = 1;
		((SetValueContext*)context)->signals[0] = EN_FURNITURE_STARTDATEPROPERTY_SIGNAL_VALUE_CHANGED;
	}
	break;

	case EN_FURNITURE_STARTTIMEPROPERTY_VALUE_PROPERTY:
	{
		TimePropertyValue newValue;
		status = unmarshalPropertyValue(&FurnitureStartTimeProperty, replyMsg, &newValue, ((SetValueContext*)context)->sender);
		if (status != AJ_OK) {
			return status;
		}
		setTimeProperty(&newValue);
		((SetValueContext*)context)->numSignals = 1;
		((SetValueContext*)context)->signals[0] = EN_FURNITURE_STARTTIMEPROPERTY_SIGNAL_VALUE_CHANGED;
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

	case EN_FURNITURE_LIGHTCONFIRM_EXEC_ACTION1:
	{
		openLamp();
	}
	break;

	case EN_FURNITURE_LIGHTCONFIRM_EXEC_ACTION2:
	{
		closeLamp();
	}
	break;

	case EN_FURNITURE_LIGHTCONFIRM_EXEC_ACTION3:
	{
		AJ_MarshalErrorMsg(msg, &reply, AJ_ErrServiceUnknown);
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
					}
					else if (context.signals[indx].signalType == SIGNAL_TYPE_DISMISS) {
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
