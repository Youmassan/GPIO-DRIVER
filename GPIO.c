
#include "GPIO.h"


void PORT_init(PORT Port){
	 SYSCTL_RCGC2_R |=(1<<Port);//enable clock port X
	 while( BIT_IS_CLEAR(SYSCTL_PRGPIO_R,Port) );

 if(Port==PortA){//unlock Pins
   GPIO_PORTA_LOCK_R=0x4c4f434B;
   GPIO_PORTA_CR_R =0xFF;
	}
else if (Port==PortB){
	 GPIO_PORTB_LOCK_R=0x4c4f434B;
	 GPIO_PORTB_CR_R =0xFF;

}
else if (Port==PortC){
	 GPIO_PORTC_LOCK_R=0x4c4f434B;
	 GPIO_PORTC_CR_R =0xFF;
}
else if (Port==PortD){
	 GPIO_PORTD_LOCK_R=0x4c4f434B;
	 GPIO_PORTD_CR_R =0xFF;
}
else if (Port==PortE){
	 GPIO_PORTE_LOCK_R=0x4c4f434B;
	 GPIO_PORTE_CR_R =0xFF;
}
else if (Port==PortF){
	GPIO_PORTF_LOCK_R=0x4c4f434B;
    GPIO_PORTF_CR_R =0xFF;
}




}
void PIN(const PIN_Config* Config_Ptr){
	if(Config_Ptr->Port==PortA){
		GPIO_PORTA_DIR_R=(CLEAR_BIT(GPIO_PORTA_DIR_R,Config_Ptr->PIN))|((Config_Ptr->Deriction)<<Config_Ptr->PIN);
		if(Config_Ptr->AnalogDigital==Digital){
			SET_BIT( GPIO_PORTA_DEN_R,Config_Ptr->PIN);
			CLEAR_BIT( GPIO_PORTA_AMSEL_R,Config_Ptr->PIN);
		}
		else{
			CLEAR_BIT( GPIO_PORTA_DEN_R,Config_Ptr->PIN);
			SET_BIT( GPIO_PORTA_AMSEL_R,Config_Ptr->PIN);
		}

		}


	else if (Config_Ptr->Port==PortB){
		GPIO_PORTB_DIR_R=(CLEAR_BIT(GPIO_PORTB_DIR_R,Config_Ptr->PIN))|((Config_Ptr->Deriction)<<Config_Ptr->PIN);
		if(Config_Ptr->AnalogDigital==Digital){
				    	SET_BIT( GPIO_PORTB_DEN_R,Config_Ptr->PIN);
				    	CLEAR_BIT( GPIO_PORTB_AMSEL_R,Config_Ptr->PIN);
				    }
				    else{
				    	CLEAR_BIT( GPIO_PORTB_DEN_R,Config_Ptr->PIN);
				    	SET_BIT( GPIO_PORTB_AMSEL_R,Config_Ptr->PIN);
				    }

	}
	else if (Config_Ptr->Port==PortC){
		GPIO_PORTC_DIR_R=(CLEAR_BIT(GPIO_PORTC_DIR_R,Config_Ptr->PIN))|((Config_Ptr->Deriction)<<Config_Ptr->PIN);

		if(Config_Ptr->AnalogDigital==Digital){
				    	SET_BIT( GPIO_PORTC_DEN_R,Config_Ptr->PIN);
				    	CLEAR_BIT( GPIO_PORTC_AMSEL_R,Config_Ptr->PIN);
				    }
				    else{
				    	CLEAR_BIT( GPIO_PORTC_DEN_R,Config_Ptr->PIN);
				    	SET_BIT( GPIO_PORTC_AMSEL_R,Config_Ptr->PIN);
				    }

	}
	else if (Config_Ptr->Port==PortD){
		GPIO_PORTD_DIR_R=(CLEAR_BIT(GPIO_PORTD_DIR_R,Config_Ptr->PIN))|((Config_Ptr->Deriction)<<Config_Ptr->PIN);

		 if(Config_Ptr->AnalogDigital==Digital){
				    	SET_BIT( GPIO_PORTD_DEN_R,Config_Ptr->PIN);
				    	CLEAR_BIT( GPIO_PORTD_AMSEL_R,Config_Ptr->PIN);
				    }
				    else{
				    	CLEAR_BIT( GPIO_PORTD_DEN_R,Config_Ptr->PIN);
				    	SET_BIT( GPIO_PORTD_AMSEL_R,Config_Ptr->PIN);
				    }
	}
	else if (Config_Ptr->Port==PortE){
		GPIO_PORTE_DIR_R=(CLEAR_BIT(GPIO_PORTE_DIR_R,Config_Ptr->PIN))|((Config_Ptr->Deriction)<<Config_Ptr->PIN);

		if(Config_Ptr->AnalogDigital==Digital){
				    	SET_BIT( GPIO_PORTE_DEN_R,Config_Ptr->PIN);
				    	CLEAR_BIT( GPIO_PORTE_AMSEL_R,Config_Ptr->PIN);
				    }
				    else{
				    	CLEAR_BIT( GPIO_PORTE_DEN_R,Config_Ptr->PIN);
				    	SET_BIT( GPIO_PORTE_AMSEL_R,Config_Ptr->PIN);
				    }
	}
	else if (Config_Ptr->Port==PortF){
		GPIO_PORTF_DIR_R=(CLEAR_BIT(GPIO_PORTF_DIR_R,Config_Ptr->PIN))|((Config_Ptr->Deriction)<<Config_Ptr->PIN);

		   if(Config_Ptr->AnalogDigital==Digital){
			    	SET_BIT( GPIO_PORTF_DEN_R,Config_Ptr->PIN);
			    	CLEAR_BIT( GPIO_PORTF_AMSEL_R,Config_Ptr->PIN);
			    }
			    else{
			    	CLEAR_BIT( GPIO_PORTF_DEN_R,Config_Ptr->PIN);
			    	SET_BIT( GPIO_PORTF_AMSEL_R,Config_Ptr->PIN);
			    }
	}

}




char ReadPin( const PinValue* ReadPin  ){
if(ReadPin->Port==PortA){
		return BIT_IS_SET(GPIO_PORTA_DATA_R ,ReadPin->PIN) ? 1 : 0;
	}
else if (ReadPin->Port==PortB){
	return BIT_IS_SET(GPIO_PORTB_DATA_R ,ReadPin->PIN) ? 1 : 0;
}
else if (ReadPin->Port==PortC){
	return BIT_IS_SET(GPIO_PORTC_DATA_R ,ReadPin->PIN) ? 1 : 0;
}
else if (ReadPin->Port==PortD){
	return BIT_IS_SET(GPIO_PORTD_DATA_R ,ReadPin->PIN) ? 1 : 0;
}
else if (ReadPin->Port==PortE){
	return BIT_IS_SET(GPIO_PORTE_DATA_R ,ReadPin->PIN) ? 1 : 0;
}
else if (ReadPin->Port==PortF){
	return BIT_IS_SET(GPIO_PORTF_DATA_R ,ReadPin->PIN) ? 1 : 0;
}

}



void WritePin(const PinValue* WritePin ){
if(WritePin->Port==PortA){
	WritePin->value? SET_BIT(GPIO_PORTA_DATA_R,WritePin->PIN):CLEAR_BIT(GPIO_PORTA_DATA_R,WritePin->PIN);
	}
else if (WritePin->Port==PortB){
	WritePin->value? SET_BIT(GPIO_PORTB_DATA_R,WritePin->PIN):CLEAR_BIT(GPIO_PORTB_DATA_R,WritePin->PIN);
}
else if (WritePin->Port==PortC){
	WritePin->value? SET_BIT(GPIO_PORTC_DATA_R,WritePin->PIN):CLEAR_BIT(GPIO_PORTC_DATA_R,WritePin->PIN);
}
else if (WritePin->Port==PortD){
	WritePin->value? SET_BIT(GPIO_PORTD_DATA_R,WritePin->PIN):CLEAR_BIT(GPIO_PORTD_DATA_R,WritePin->PIN);
}
else if (WritePin->Port==PortE){
	WritePin->value? SET_BIT(GPIO_PORTE_DATA_R,WritePin->PIN):CLEAR_BIT(GPIO_PORTE_DATA_R,WritePin->PIN);
}
else if (WritePin->Port==PortF){
	WritePin->value? SET_BIT(GPIO_PORTF_DATA_R,WritePin->PIN):CLEAR_BIT(GPIO_PORTF_DATA_R,WritePin->PIN);
}
}


void EnablePUR(const PinValue* Resistor){
	if(Resistor->Port==PortA){
		SET_BIT(GPIO_PORTA_PUR_R,Resistor->PIN);
	}
	else if (Resistor->Port==PortB){
		SET_BIT(GPIO_PORTB_PUR_R,Resistor->PIN);
	}
	else if (Resistor->Port==PortC){
		SET_BIT(GPIO_PORTC_PUR_R,Resistor->PIN);
	}
	else if (Resistor->Port==PortD){
		SET_BIT(GPIO_PORTD_PUR_R,Resistor->PIN);
	}
	else if (Resistor->Port==PortE){
		SET_BIT(GPIO_PORTE_PUR_R,Resistor->PIN);
	}
	else if (Resistor->Port==PortF){
		SET_BIT(GPIO_PORTF_PUR_R,Resistor->PIN);
	}
}

void EnablePDR(const PinValue* Resistor){
	if(Resistor->Port==PortA){
		SET_BIT(GPIO_PORTA_PDR_R,Resistor->PIN);
	}
	else if (Resistor->Port==PortB){
		SET_BIT(GPIO_PORTB_PDR_R,Resistor->PIN);
	}
	else if (Resistor->Port==PortC){
		SET_BIT(GPIO_PORTC_PDR_R,Resistor->PIN);
	}
	else if (Resistor->Port==PortD){
		SET_BIT(GPIO_PORTD_PDR_R,Resistor->PIN);
	}
	else if (Resistor->Port==PortE){
		SET_BIT(GPIO_PORTE_PDR_R,Resistor->PIN);
	}
	else if (Resistor->Port==PortF){
		SET_BIT(GPIO_PORTF_PDR_R,Resistor->PIN);
	}
}

