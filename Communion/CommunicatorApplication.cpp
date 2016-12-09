/*
 * CommunicatiorApplication.cpp
 *
 *  Created on: 2016年10月31日
 *      Author: nico
 */

#include "CommunicatorApplication.h"
#include <Console/Console.h>
#include <Service/Service.h>

namespace NS_Communion {

  CommunicatorApplication::CommunicatorApplication() {
	  instance = this;
  }

  CommunicatorApplication::~CommunicatorApplication() {

  }

  void CommunicatorApplication::loadParameters() {

  }

  void CommunicatorApplication::onTimeout(CommData* timeout_message)
  {
    if(timeout_message != NULL)
      delete timeout_message;
  }

  void CommunicatorApplication::onReceive(CommData* message)
  {
    if (message != NULL) {
    	CommData* response = createResponseByRequest(message);
    	NS_ServiceType::ResponseBase* serResponse;
    	if (message->type == COMMUNICATION_DATA_REASON_MAP) {
    		service->call(SERVICE_TYPE_MAP, NULL, serResponse);
    	}
    	sendResponse(response);
    }
  }

  void  CommunicatorApplication::initialize()
  {
  	NS_NaviCommon::console.message("Communion is initializing!");

  	loadParameters();
    instance->initialize(80);
    initialized = true;

  }

  void CommunicatorApplication::run()
  {
  	NS_NaviCommon::console.message("Communion is running!");

  	Application::running = true;


  }

  void CommunicatorApplication::quit()
  {
  	NS_NaviCommon::console.message("Communion is quitting!");

    Application::running = false;
  }
}


