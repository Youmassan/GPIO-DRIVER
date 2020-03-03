
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
void PIN(PORT Port ,char PIN,AnaDig AnalogDigital,DERICTION Deriction){
	if(Port==PortA){
		GPIO_PORTA_DIR_R=(CLEAR_BIT(GPIO_PORTA_DIR_R,PIN))|((Deriction)<<PIN);
		if(AnalogDigital==Digital){
			SET_BIT( GPIO_PORTA_DEN_R,PIN);
			CLEAR_BIT( GPIO_PORTA_AMSEL_R,PIN);
		}
		else{
			CLEAR_BIT( GPIO_PORTA_DEN_R,PIN);
			SET_BIT( GPIO_PORTA_AMSEL_R,PIN);
		}

		}


	else if (Port==PortB){
		GPIO_PORTB_DIR_R=(CLEAR_BIT(GPIO_PORTB_DIR_R,PIN))|((Deriction)<<PIN);
		if(AnalogDigital==Digital){
				    	SET_BIT( GPIO_PORTB_DEN_R,PIN);
				    	CLEAR_BIT( GPIO_PORTB_AMSEL_R,PIN);
				    }
				    else{
				    	CLEAR_BIT( GPIO_PORTB_DEN_R,PIN);
				    	SET_BIT( GPIO_PORTB_AMSEL_R,PIN);
				    }

	}
	else if (Port==PortC){
		GPIO_PORTC_DIR_R=(CLEAR_BIT(GPIO_PORTC_DIR_R,PIN))|((Deriction)<<PIN);

		if(AnalogDigital==Digital){
				    	SET_BIT( GPIO_PORTC_DEN_R,PIN);
				    	CLEAR_BIT( GPIO_PORTC_AMSEL_R,PIN);
				    }
				    else{
				    	CLEAR_BIT( GPIO_PORTC_DEN_R,PIN);
				    	SET_BIT( GPIO_PORTC_AMSEL_R,PIN);
				    }

	}
	else if (Port==PortD){
		GPIO_PORTD_DIR_R=(CLEAR_BIT(GPIO_PORTD_DIR_R,PIN))|((Deriction)<<PIN);

		 if(AnalogDigital==Digital){
				    	SET_BIT( GPIO_PORTD_DEN_R,PIN);
				    	CLEAR_BIT( GPIO_PORTD_AMSEL_R,PIN);
				    }
				    else{
				    	CLEAR_BIT( GPIO_PORTD_DEN_R,PIN);
				    	SET_BIT( GPIO_PORTD_AMSEL_R,PIN);
				    }
	}
	else if (Port==PortE){
		GPIO_PORTE_DIR_R=(CLEAR_BIT(GPIO_PORTE_DIR_R,PIN))|((Deriction)<<PIN);

		if(AnalogDigital==Digital){
				    	SET_BIT( GPIO_PORTE_DEN_R,PIN);
				    	CLEAR_BIT( GPIO_PORTE_AMSEL_R,PIN);
				    }
				    else{
				    	CLEAR_BIT( GPIO_PORTE_DEN_R,PIN);
				    	SET_BIT( GPIO_PORTE_AMSEL_R,PIN);
				    }
	}
	else if (Port==PortF){
		GPIO_PORTF_DIR_R=(CLEAR_BIT(GPIO_PORTF_DIR_R,PIN))|((Deriction)<<PIN);

		   if(AnalogDigital==Digital){
			    	SET_BIT( GPIO_PORTF_DEN_R,PIN);
			    	CLEAR_BIT( GPIO_PORTF_AMSEL_R,PIN);
			    }
			    else{
			    	CLEAR_BIT( GPIO_PORTF_DEN_R,PIN);
			    	SET_BIT( GPIO_PORTF_AMSEL_R,PIN);
			    }
	}

}




char ReadPin(PORT Port,char PIN ){
if(Port==PortA){
	return BIT_IS_SET(GPIO_PORTA_DATA_R ,PIN) ? 1 : 0;
	}
else if (Port==PortB){
	return BIT_IS_SET(GPIO_PORTB_DATA_R ,PIN) ? 1 : 0;
}
else if (Port==PortC){
	return BIT_IS_SET(GPIO_PORTC_DATA_R ,PIN) ? 1 : 0;
}
else if (Port==PortD){
	return BIT_IS_SET(GPIO_PORTD_DATA_R ,PIN) ? 1 : 0;
}
else if (Port==PortE){
	return BIT_IS_SET(GPIO_PORTE_DATA_R ,PIN) ? 1 : 0;
}
else if (Port==PortF){
	return BIT_IS_SET(GPIO_PORTF_DATA_R ,PIN) ? 1 : 0;
}

}



void WritePin(PORT Port,char PIN,char value ){
if(Port==PortA){
	value? SET_BIT(GPIO_PORTA_DATA_R,PIN):CLEAR_BIT(GPIO_PORTA_DATA_R,PIN);
	}
else if (Port==PortB){
	value? SET_BIT(GPIO_PORTB_DATA_R,PIN):CLEAR_BIT(GPIO_PORTB_DATA_R,PIN);
}
else if (Port==PortC){
	value? SET_BIT(GPIO_PORTC_DATA_R,PIN):CLEAR_BIT(GPIO_PORTC_DATA_R,PIN);
}
else if (Port==PortD){
    value? SET_BIT(GPIO_PORTD_DATA_R,PIN):CLEAR_BIT(GPIO_PORTD_DATA_R,PIN);
}
else if (Port==PortE){
	value? SET_BIT(GPIO_PORTE_DATA_R,PIN):CLEAR_BIT(GPIO_PORTE_DATA_R,PIN);
}
else if (Port==PortF){
	value? SET_BIT(GPIO_PORTF_DATA_R,PIN):CLEAR_BIT(GPIO_PORTF_DATA_R,PIN);
}
}


void EnablePUR(PORT Port,char PIN){
	if(Port==PortA){
		SET_BIT(GPIO_PORTA_PUR_R,PIN);
	}
	else if (Port==PortB){
		SET_BIT(GPIO_PORTB_PUR_R,PIN);
	}
	else if (Port==PortC){
		SET_BIT(GPIO_PORTC_PUR_R,PIN);
	}
	else if (Port==PortD){
		SET_BIT(GPIO_PORTD_PUR_R,PIN);
	}
	else if (Port==PortE){
		SET_BIT(GPIO_PORTE_PUR_R,PIN);
	}
	else if (Port==PortF){
		SET_BIT(GPIO_PORTF_PUR_R,PIN);
	}
}

void EnablePDR(PORT Port,char PIN){
	if(Port==PortA){
		SET_BIT(GPIO_PORTA_PDR_R,PIN);
	}
	else if (Port==PortB){
		SET_BIT(GPIO_PORTB_PDR_R,PIN);
	}
	else if (Port==PortC){
		SET_BIT(GPIO_PORTC_PDR_R,PIN);
	}
	else if (Port==PortD){
		SET_BIT(GPIO_PORTD_PDR_R,PIN);
	}
	else if (Port==PortE){
		SET_BIT(GPIO_PORTE_PDR_R,PIN);
	}
	else if (Port==PortF){
		SET_BIT(GPIO_PORTF_PDR_R,PIN);
	}
}

