#include "IODefine.c"

unsigned char RedTable[16];
unsigned char GreenTable[16];
unsigned char BlueTable[16];  
///////////////////////////////////////////////////////////////////////////////////////////////////////
//   
//È«°µ
//-----------------------------------------------------------------------------------------------
void Clr(void)
{
      unsigned char m; 
      for(m=0;m<16;m++)
      {
        RedTable[m]=0x00;
        GreenTable[m]=0x00;
        BlueTable[m]=0x00; 
        if(BeginRcvFlag)break;      
      }   
}
//------------------------------------------------------------------------------------------------
//¾²Ì¬ºì
void StaticRed(void)
{
        unsigned char m; 
        for(m=0;m<16;m++)
        {
                RedTable[m]=0xff;
                GreenTable[m]=0x00;
                BlueTable[m]=0x00; 
                if(BeginRcvFlag)break;      
        }
}
//------------------------------------------------------------------------------------------------
//¾²Ì¬ÂÌ
void StaticGreen(void)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0xff;
                BlueTable[m]=0x00; 
                if(BeginRcvFlag)break;      
        }
}
//------------------------------------------------------------------------------------------------
//¾²Ì¬À¶
void StaticBlue(void)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0x00;
                BlueTable[m]=0xff; 
                if(BeginRcvFlag)break;      
        }
}      

//------------------------------------------------------------------------------------------------
//¾²Ì¬»Æ
void StaticYellow(void)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0xff;
                GreenTable[m]=0xff;
                BlueTable[m]=0x00;   
                if(BeginRcvFlag)break;    
        }
}
//------------------------------------------------------------------------------------------------
//¾²Ì¬Çà
void StaticCyan(void)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0xff;
                BlueTable[m]=0xff; 
                if(BeginRcvFlag)break;      
        }
}  
//------------------------------------------------------------------------------------------------
//¾²Ì¬×Ï
void StaticPurple(void)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0xff;
                BlueTable[m]=0xff;
                if(BeginRcvFlag)break;       
        }
}  
//------------------------------------------------------------------------------------------------
//¾²Ì¬°×
void StaticWhite(void)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0xff;
                GreenTable[m]=0xff;
                BlueTable[m]=0xff; 
                if(BeginRcvFlag)break;      
        }
} 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//È«ÉÁË¸ 
//ºìÉÁ
//------------------------------------------------------------------------------------------------
void RedSynchFlash(unsigned char Spd)
{
        unsigned char m;    
        for(m=0;m<16;m++)
        {
                RedTable[m]=0xff;
                GreenTable[m]=0x00;
                BlueTable[m]=0x00;  
                if(BeginRcvFlag)break;  
        }
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0x00;
                BlueTable[m]=0x00; 
                if(BeginRcvFlag)break;   
        } 
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
}
//------------------------------------------------------------------------------------------------
//ÂÌÉÁ
void GreenSynchFlash(unsigned char Spd)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0xff;
                BlueTable[m]=0x00; 
                if(BeginRcvFlag)break;      
        }
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0x00;
                BlueTable[m]=0x00;  
                if(BeginRcvFlag)break;     
        } 
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
}
//------------------------------------------------------------------------------------------------
//À¶ÉÁ
void BlueSynchFlash(unsigned char Spd)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0x00;
                BlueTable[m]=0xff; 
                if(BeginRcvFlag)break;      
        }
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0x00;
                BlueTable[m]=0x00;   
                if(BeginRcvFlag)break;    
        } 
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
}
//------------------------------------------------------------------------------------------------
//»ÆÉÁ
void YellowSynchFlash(unsigned char Spd)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0xff;
                GreenTable[m]=0xff;
                BlueTable[m]=0x00;  
                if(BeginRcvFlag)break;     
        }
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0x00;
                BlueTable[m]=0x00; 
                if(BeginRcvFlag)break;      
        } 
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
}
//------------------------------------------------------------------------------------------------
//ÇàÉÁ
void CyanSynchFlash(unsigned char Spd)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0xff;
                BlueTable[m]=0xff; 
                if(BeginRcvFlag)break;      
        }
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0x00;
                BlueTable[m]=0x00; 
                if(BeginRcvFlag)break;      
        } 
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
}    
//------------------------------------------------------------------------------------------------
//×ÏÉÁ
void PurpleSynchFlash(unsigned char Spd)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0xff;
                GreenTable[m]=0x00;
                BlueTable[m]=0xff; 
                if(BeginRcvFlag)break;      
        }
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break; }
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0x00;
                BlueTable[m]=0x00; 
                if(BeginRcvFlag)break;      
        } 
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
}   
//-------------------------------------------------------------------------------------------------- 
//°×ÉÁ
void WhiteSynchFlash(unsigned char Spd)
{
        unsigned char m;
        for(m=0;m<16;m++)
        {
                RedTable[m]=0xff;
                GreenTable[m]=0xff;
                BlueTable[m]=0xff; 
                if(BeginRcvFlag)break;      
        }
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        for(m=0;m<16;m++)
        {
                RedTable[m]=0x00;
                GreenTable[m]=0x00;
                BlueTable[m]=0x00; 
                if(BeginRcvFlag)break;      
        } 
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
}                 
//------------------------------------------------------------------------------------------------
//ÆßÉ«ÉÁ±ä
void SevenSynchFlash(unsigned char Spd)
{
        unsigned char m;
        StaticRed();
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        StaticGreen();
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        StaticBlue();
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        StaticYellow();
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        StaticPurple();
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
        StaticWhite();
        for(m=0;m<Spd;m++){delay_us(10);if(BeginRcvFlag)break;}
}  
///////////////////////////////////////////////////////////////////////////////////////////////////
//½¥Ã÷½¥°µ    
//ºì½¥±ä
//------------------------------------------------------------------------------------------------
void RedSynchSmooth(unsigned char Spd)
{
        unsigned char m,n,k; 
        Clr();
        for(m=0;m<16;m++)
        {          
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                RedTable[n]=m;
                                if(BeginRcvFlag)break;
                        } 
                        if(BeginRcvFlag)break; 
                }
                if(BeginRcvFlag)break;
                
        }
        
        for(m=15;m>0;m--)
        {       
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                RedTable[n]=m;
                                if(BeginRcvFlag)break;
                        }
                        if(BeginRcvFlag)break;
                }
                if(BeginRcvFlag)break;
        }          
}   
//-----------------------------------------------------------------------------------------------
//ÂÌ½¥±ä
void GreenSynchSmooth(unsigned char Spd)
{
        unsigned char m,n,k; 
        Clr();
        for(m=0;m<16;m++)
        {          
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                GreenTable[n]=m;
                                if(BeginRcvFlag)break;
                        } 
                        if(BeginRcvFlag)break; 
                }
                if(BeginRcvFlag)break;
                
        }
        
        for(m=15;m>0;m--)
        {       
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                GreenTable[n]=m;
                                if(BeginRcvFlag)break;
                        }
                        if(BeginRcvFlag)break; 
                }
                if(BeginRcvFlag)break;
        }          
}   
//-----------------------------------------------------------------------------------------------
//À¶½¥±ä
void BlueSynchSmooth(unsigned char Spd)
{
        unsigned char m,n,k; 
        Clr();
        for(m=0;m<16;m++)
        {          
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                BlueTable[n]=m;
                                if(BeginRcvFlag)break;
                        } 
                        if(BeginRcvFlag)break; 
                }
                if(BeginRcvFlag)break;
                
        }
        
        for(m=15;m>0;m--)
        {       
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                BlueTable[n]=m;
                                if(BeginRcvFlag)break;
                        } 
                        if(BeginRcvFlag)break;
                }
                if(BeginRcvFlag)break;
        }          
}            
//-----------------------------------------------------------------------------------------------
//»Æ½¥±ä
void YellowSynchSmooth(unsigned char Spd)
{
         unsigned char m,n,k; 
        Clr();
        for(m=0;m<16;m++)
        {          
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                RedTable[n]=m;
                                GreenTable[n]=m;
                                if(BeginRcvFlag)break;
                        }  
                        if(BeginRcvFlag)break;
                }
                if(BeginRcvFlag)break;
                
        }
        
        for(m=15;m>0;m--)
        {       
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                RedTable[n]=m;
                                GreenTable[n]=m;
                                if(BeginRcvFlag)break;
                        } 
                        if(BeginRcvFlag)break;
                }
                if(BeginRcvFlag)break;
        }          
}   
//-----------------------------------------------------------------------------------------------
//Çà½¥±ä
void CyanSynchSmooth(unsigned char Spd)
{
        unsigned char m,n,k; 
        Clr();
        for(m=0;m<16;m++)
        {          
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                BlueTable[n]=m;
                                GreenTable[n]=m;
                                if(BeginRcvFlag)break;
                        } 
                        if(BeginRcvFlag)break; 
                }
                if(BeginRcvFlag)break;
                
        }
        
        for(m=15;m>0;m--)
        {       
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                BlueTable[n]=m;
                                GreenTable[n]=m;
                                if(BeginRcvFlag)break;
                        } 
                        if(BeginRcvFlag)break;
                }
                if(BeginRcvFlag)break;
        }          
}    
//-----------------------------------------------------------------------------------------------
//×Ï½¥±ä
void PurpleSynchSmooth(unsigned char Spd)
{
        unsigned char m,n,k; 
        Clr();
        for(m=0;m<16;m++)
        {          
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                BlueTable[n]=m;
                                RedTable[n]=m;
                                if(BeginRcvFlag)break;
                        }
                        if(BeginRcvFlag)break;
                }
                if(BeginRcvFlag)break;
        }
        
        for(m=16;m>0;m--)
        {       
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                BlueTable[n]=m;
                                RedTable[n]=m;
                                if(BeginRcvFlag)break;
                        } 
                        if(BeginRcvFlag)break;
                }
                if(BeginRcvFlag)break;
        }          
}   
//-----------------------------------------------------------------------------------------------
//°×½¥±ä
void WhiteSynchSmooth(unsigned char Spd)
{
         unsigned char m,n,k; 
        Clr();
        for(m=0;m<16;m++)
        {          
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                BlueTable[n]=m;
                                RedTable[n]=m;
                                GreenTable[n]=m;
                                if(BeginRcvFlag)break;
                        }
                        if(BeginRcvFlag)break;
                }
                if(BeginRcvFlag)break;
        }
        
        for(m=16;m>0;m--)
        {       
                for(k=0;k<Spd;k++)
                {
                        for(n=0;n<16;n++)
                        {
                                BlueTable[n]=m;
                                RedTable[n]=m;
                                GreenTable[n]=m;
                                if(BeginRcvFlag)break;
                        } 
                        if(BeginRcvFlag)break;
                }
                if(BeginRcvFlag)break;
        }          
}  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//½¥°µ½¥Ã÷Ç°×·
//----------------------------------------------------------------------------------------------
void RedDimToBrightForwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;} 
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;} 
        for(m=0;m<16*4;m++)
        {
                if(RedTable[0]<16)RedTable[0]++;
                for(n=0;n<15;n++)
                {
                        if((RedTable[n]>3)&(RedTable[n+1]<16))RedTable[n+1]++;
                        if(BeginRcvFlag)break;	
                }
                for(k=0;k<Spd;k++){delay_us(5);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }
}
//----------------------------------------------------------------------------------------------
void GreenDimToBrightForwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(GreenTable[0]<16)GreenTable[0]++;  
                for(n=0;n<15;n++)
                {
                     if((GreenTable[n]>3)&(GreenTable[n+1]<16))GreenTable[n+1]++;  
                     if(BeginRcvFlag)break; 
                } 
                for(k=0;k<Spd;k++){delay_us(5);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }
}
//----------------------------------------------------------------------------------------------
void BlueDimToBrightForwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break; }
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break; }
        for(m=0;m<16*4;m++)
        {
                if(BlueTable[0]<16)BlueTable[0]++;   
                for(n=0;n<15;n++)
                {
                    if((BlueTable[n]>3)&(BlueTable[n+1]<16))BlueTable[n+1]++; 
                    if(BeginRcvFlag)break;   
                }
                for(k=0;k<Spd;k++)delay_us(5);
                if(BeginRcvFlag)break;
        }
} 
//----------------------------------------------------------------------------------------------
void YellowDimToBrightForwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(GreenTable[0]<16)
                {
                        RedTable[0]++;
                        GreenTable[0]++;
                } 
                for(n=0;n<15;n++)
                {
                    if((GreenTable[n]>3)&(GreenTable[n+1]<16)) 
                    {
                         RedTable[n+1]++;
                        GreenTable[n+1]++; 
                    }
                    if(BeginRcvFlag)break;   
                }
                for(k=0;k<Spd;k++){delay_us(5);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;	
        }
}                               
//----------------------------------------------------------------------------------------------
void CyanDimToBrightForwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(BlueTable[0]<16)
                {                      
                        GreenTable[0]++;
                        BlueTable[0]++;
                }
                for(n=0;n<15;n++)
                {               
                       if((BlueTable[n]>3)&(BlueTable[n+1]<16))
                       {
                        GreenTable[n+1]++;
                        BlueTable[n+1]++;
                        }
                        if(BeginRcvFlag)break;                  
                }
                for(k=0;k<Spd;k++){delay_us(5);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }
}    
//---------------------------------------------------------------------------------------------
void PurpleDimToBrightForwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(BlueTable[0]<16)
                {                      
                        RedTable[0]++;
                        BlueTable[0]++;
                } 
                for(n=0;n<15;n++)
                {
                    if((BlueTable[n]>3)&(BlueTable[n+1]<16))
                        {
                        RedTable[n+1]++;
                        BlueTable[n+1]++;
                        }
                        if(BeginRcvFlag)break;         
                }
                for(k=0;k<Spd;k++){delay_us(5);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }
}    

//----------------------------------------------------------------------------------------------
void WhiteDimToBrightForwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(BlueTable[0]<16)
                {         
                        RedTable[0]++;           
                        GreenTable[0]++;
                        BlueTable[0]++;
                } 
                for(n=0;n<15;n++)
                {
                    if((BlueTable[n]>3)&(BlueTable[n+1]<16))
                        {          
                        RedTable[n+1]++;
                        GreenTable[n+1]++;
                        BlueTable[n+1]++;
                        }
                        if(BeginRcvFlag)break;      
                }    
                for(k=0;k<Spd;k++){delay_us(5);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }
}  
//////////////////////////////////////////////////////////////////////////////////////////////////////
//½¥°µ½¥Ã÷»Ø×·          
//--------------------------------------------------------------------------------------------------
void RedDimToBrightBackwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(RedTable[15]<16)RedTable[15]++;
                for(n=15;n>0;n--)
                {
                        if((RedTable[n]>3)&(RedTable[n-1]<16))RedTable[n-1]++;
                        if(BeginRcvFlag)break;
                }
                for(k=0;k<Spd;k++){delay_us(1);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }       
}                             
//--------------------------------------------------------------------------------------------------
void GreenDimToBrightBackwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(GreenTable[15]<16)GreenTable[15]++;
                 for(n=15;n>0;n--)
                 {
                   if((GreenTable[n]>3)&(GreenTable[n-1]<16))GreenTable[n-1]++;
                   	if(BeginRcvFlag)break;
                 }
                for(k=0;k<Spd;k++){delay_us(1);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }       
}       
//--------------------------------------------------------------------------------------------------
void BlueDimToBrightBackwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(BlueTable[15]<16)BlueTable[15]++;
                for(n=15;n>0;n--)
                {
                      if((BlueTable[n]>3)&(BlueTable[n-1]<16))BlueTable[n-1]++; 
                      if(BeginRcvFlag)break; 
                }
                for(k=0;k<Spd;k++){delay_us(1);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }       
}      
//--------------------------------------------------------------------------------------------------
void YellowDimToBrightBackwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(GreenTable[15]<16)
                {
                        RedTable[15]++;
                        GreenTable[15]++;
                } 
                for(n=15;n>0;n--)
                {
                      if((GreenTable[n]>3)&(GreenTable[n-1]<16))      
                      {
                        RedTable[n-1]++;
                        GreenTable[n-1]++;
                      }  
                      if(BeginRcvFlag)break;
                }
                for(k=0;k<Spd;k++){delay_us(1);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }       
}  
//--------------------------------------------------------------------------------------------------
void CyanDimToBrightBackwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(GreenTable[15]<16) 
                {
                        BlueTable[15]++;
                        GreenTable[15]++;
                } 
                for(n=15;n>0;n--)
                {              
                   if((GreenTable[n]>3)&(GreenTable[n-1]<16))      
                   {
                        BlueTable[n-1]++;
                        GreenTable[n-1]++;
                   }  
                   if(BeginRcvFlag)break;   
                }    
                for(k=0;k<Spd;k++){delay_us(1);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }       
}                   
//--------------------------------------------------------------------------------------------------
void PurpleDimToBrightBackwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(BlueTable[15]<16)                          
                {
                        RedTable[15]++;
                        BlueTable[15]++;
                }
                for(n=15;n>0;n--)
                {
                   if((BlueTable[n]>3)&(BlueTable[n-1]<16))      
                   {
                        RedTable[n-1]++;
                        BlueTable[n-1]++;
                   } 
                   if(BeginRcvFlag)break;    
                }
                for(k=0;k<Spd;k++){delay_us(1);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }       
}                           
//--------------------------------------------------------------------------------------------------
void WhiteDimToBrightBackwardChase(unsigned char Spd)
{
        unsigned char m,n,k;
        
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16*4;m++)
        {
                if(BlueTable[15]<16)                          
                {
                        RedTable[15]++;
                        GreenTable[15]++;
                        BlueTable[15]++;
                }
                for(n=15;n>0;n--)
                { 
                        if((BlueTable[n]>3)&(BlueTable[n-1]<16))      
                        {
                                RedTable[n-1]++;
                                GreenTable[n-1]++;
                                BlueTable[n-1]++;
                        }
                        if(BeginRcvFlag)break;
                } 
              for(k=0;k<Spd;k++){delay_us(1);if(BeginRcvFlag)break;}
              if(BeginRcvFlag)break;
        }       
}   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//»ÛÐÇÇ°×·
//-----------------------------------------------------------------------------------------------------------
void RedCometForward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=15;n>0;n--){RedTable[n]=RedTable[n-1];if(BeginRcvFlag)break;}
                RedTable[0]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}    
//-----------------------------------------------------------------------------------------------------------
void GreenCometForward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=15;n>0;n--){GreenTable[n]=GreenTable[n-1];if(BeginRcvFlag)break;}
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}    
//-----------------------------------------------------------------------------------------------------------
void BlueCometForward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=15;n>0;n--){BlueTable[n]=BlueTable[n-1];if(BeginRcvFlag)break;}
                BlueTable[0]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}    
//-----------------------------------------------------------------------------------------------------------
void YellowCometForward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=15;n>0;n--)
                {
                	GreenTable[n]=GreenTable[n-1];
                	RedTable[n]=RedTable[n-1];
                	if(BeginRcvFlag)break;
                }
                GreenTable[0]=j[m];  
                RedTable[0]=j[m]; 
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}    
//-----------------------------------------------------------------------------------------------------------
void CyanCometForward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=15;n>0;n--)
                {
                	GreenTable[n]=GreenTable[n-1];
                	BlueTable[n]=BlueTable[n-1];
                	if(BeginRcvFlag)break;
                }
                GreenTable[0]=j[m];  
                BlueTable[0]=j[m]; 
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
        }    
}                       
//-----------------------------------------------------------------------------------------------------------
void PurpleCometForward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=15;n>0;n--)
                {
                	RedTable[n]=RedTable[n-1];
                	BlueTable[n]=BlueTable[n-1];
                	if(BeginRcvFlag)break;
                }
                RedTable[0]=j[m];  
                BlueTable[0]=j[m]; 
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}               
//-----------------------------------------------------------------------------------------------------------
void WhiteCometForward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=15;n>0;n--)
                {
                	RedTable[n]=RedTable[n-1];
                	GreenTable[n]=GreenTable[n-1];
                	BlueTable[n]=BlueTable[n-1];
                	if(BeginRcvFlag)break;
                }
                RedTable[0]=j[m];
                GreenTable[0]=j[m];  
                BlueTable[0]=j[m]; 
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
//»ÛÐÇ»Ø×·   
//-----------------------------------------------------------------------------------------------------------
void RedCometBackward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=0;n<15;n++){RedTable[n]=RedTable[n+1];if(BeginRcvFlag)break;}
                RedTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}    
//-----------------------------------------------------------------------------------------------------------
void GreenCometBackward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=0;n<15;n++){GreenTable[n]=GreenTable[n+1];if(BeginRcvFlag)break;}
                GreenTable[15]=j[m];
                for(k=0;k<Spd;k++)delay_us(10);if(BeginRcvFlag)break;
                if(BeginRcvFlag)break;
        }    
}    
//-----------------------------------------------------------------------------------------------------------
void BlueCometBackward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=0;n<15;n++){BlueTable[n]=BlueTable[n+1];if(BeginRcvFlag)break;}
                BlueTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}    
//-----------------------------------------------------------------------------------------------------------
void YellowCometBackward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {      
                for(n=0;n<15;n++)
                {
                	RedTable[n]=RedTable[n+1];
                  GreenTable[n]=GreenTable[n+1];
                  if(BeginRcvFlag)break;
                }
                RedTable[15]=j[m];
                GreenTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}    
//-----------------------------------------------------------------------------------------------------------
void CyanCometBackward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=0;n<15;n++)
                {
                	BlueTable[n]=BlueTable[n+1];
                	GreenTable[n]=GreenTable[n+1];
                	if(BeginRcvFlag)break;	
                }
                BlueTable[15]=j[m];
                GreenTable[15]=j[m]; 
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}    
//-----------------------------------------------------------------------------------------------------------
void PurpleCometBackward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=0;n<15;n++)
                {
                	RedTable[n]=RedTable[n+1];
                	BlueTable[n]=BlueTable[n+1];
                	if(BeginRcvFlag)break;
                }
                RedTable[15]=j[m];
                BlueTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
}    
//-----------------------------------------------------------------------------------------------------------
void WhiteCometBackward(unsigned char Spd)
{
        unsigned char m,n,k; 
        unsigned char j[20]={16,10,6,3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<20;m++)
        {       
                for(n=0;n<15;n++)
                {
                	RedTable[n]=RedTable[n-1];
                	GreenTable[n]=GreenTable[n-1];
                	BlueTable[n]=BlueTable[n-1];
                	if(BeginRcvFlag)break;
                }
                RedTable[15]=j[m];
                GreenTable[15]=j[m];
                BlueTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    
} 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//²¨ÀËÇ°×·
//---------------------------------------------------------------------------------------------
void RedWaveForwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        //for(m=0;m<16;m++)RedTable[m]=0x00; 
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<21;m++)
        {       
                //RedTable[0]=j[m];
                for(n=15;n>0;n--)
                {
                        RedTable[n]=RedTable[n-1];if(BeginRcvFlag)break;
                }
                RedTable[0]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
//---------------------------------------------------------------------------------------------
void GreenWaveForwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        //for(m=0;m<16;m++)GreenTable[m]=0x00;
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<21;m++)
        {       
                for(n=15;n>0;n--){GreenTable[n]=GreenTable[n-1];if(BeginRcvFlag)break;}
          			GreenTable[0]=j[m];                
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
//---------------------------------------------------------------------------------------------
void BlueWaveForwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        //for(m=0;m<16;m++)BlueTable[m]=0x00; 
        for(m=0;m<21;m++)
        {       
                for(n=0;n<15;n++){BlueTable[n]=BlueTable[n+1];if(BeginRcvFlag)break;}
                BlueTable[15]=j[m]; 							      
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
 //---------------------------------------------------------------------------------------------
void YellowWaveForwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        //for(m=0;m<16;m++)RedTable[m]=0x00; 
        //for(m=0;m<16;m++)GreenTable[m]=0x00;
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<21;m++)
        {       
               
                for(n=15;n>0;n--)
                {
                	RedTable[n]=RedTable[n-1];
                	GreenTable[n]=GreenTable[n-1];
                	if(BeginRcvFlag)break;
                }
                RedTable[0]=j[m];
                GreenTable[0]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}   
 
 //---------------------------------------------------------------------------------------------
void CyanWaveForwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        //for(m=0;m<16;m++)GreenTable[m]=0x00;
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<21;m++)
        {       
                for(n=15;n>0;n--)
                {
                	GreenTable[n]=GreenTable[n-1];
                	BlueTable[n]=BlueTable[n-1];
                	if(BeginRcvFlag)break;
                }
                GreenTable[0]=j[m];
                BlueTable[0]=j[m]; 			            
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
} 
//---------------------------------------------------------------------------------------------
void PurpleWaveForwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        //for(m=0;m<16;m++)RedTable[m]=0x00; 
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        //for(m=0;m<16;m++)BlueTable[m]=0x00; 
        for(m=0;m<21;m++)
        {       
                for(n=15;n>0;n--)
                {
                	RedTable[n]=RedTable[n-1];
                	BlueTable[n]=BlueTable[n-1];
                	if(BeginRcvFlag)break;
                }
                RedTable[0]=j[m];
                BlueTable[0]=j[m]; 			    
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
//---------------------------------------------------------------------------------------------
void WhiteWaveForwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        //for(m=0;m<16;m++)RedTable[m]=0x00; 
        //for(m=0;m<16;m++)GreenTable[m]=0x00;
        //for(m=0;m<16;m++)BlueTable[m]=0x00; 
        for(m=0;m<21;m++)
        {       
                for(n=15;n>0;n--)
                {
                	RedTable[n]=RedTable[n-1];
                	GreenTable[n]=GreenTable[n-1];
                	BlueTable[n]=BlueTable[n-1];
                	if(BeginRcvFlag)break;
                }
                RedTable[0]=j[m];
                BlueTable[0]=j[m]; 
                GreenTable[0]=j[m];			    
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}              
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//²¨ÀË»Ø×·
//---------------------------------------------------------------------------------------------
void RedWaveBackwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        //for(m=0;m<16;m++)BlueTable[m]=0x00; 
        for(m=0;m<21;m++)
        {      
                for(n=0;n<15;n++){RedTable[n]=RedTable[n+1];if(BeginRcvFlag)break;}
                RedTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
//---------------------------------------------------------------------------------------------
void GreenWaveBackwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        //for(m=0;m<16;m++)GreenTable[m]=0x00;
        for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break; }
        for(m=0;m<21;m++)
        {       
                for(n=0;n<15;n++){GreenTable[n]=GreenTable[n+1];if(BeginRcvFlag)break;}
                GreenTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
//---------------------------------------------------------------------------------------------
void BlueWaveBackwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        //for(m=0;m<16;m++)BlueTable[m]=0x00; 
        for(m=0;m<21;m++)
        {       
                for(n=0;n<15;n++){BlueTable[n]=BlueTable[n+1];if(BeginRcvFlag)break;}
                BlueTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
//---------------------------------------------------------------------------------------------
void CyanWaveBackwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        //for(m=0;m<16;m++)GreenTable[m]=0x00;
       // for(m=0;m<16;m++)BlueTable[m]=0x00; 
        for(m=0;m<21;m++)
        {       
                for(n=0;n<15;n++)
                {
                	BlueTable[n]=BlueTable[n+1];
                	GreenTable[n]=GreenTable[n+1];
                	if(BeginRcvFlag)break;
                }
                BlueTable[15]=j[m];
                GreenTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
//---------------------------------------------------------------------------------------------
void YellowWaveBackwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
       // for(m=0;m<16;m++)BlueTable[m]=0x00; 
        for(m=0;m<21;m++)
        {       
                for(n=0;n<15;n++)
                {
                	 RedTable[n]=RedTable[n+1];
                	GreenTable[n]=GreenTable[n+1];
                	if(BeginRcvFlag)break;
                }
                RedTable[15]=j[m];
                GreenTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
//---------------------------------------------------------------------------------------------
void PurpleWaveBackwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[21]={1,3,6,10,12,16,12,10,6,3,1,3,6,10,12,16,12,10,6,3,1};
        //for(m=0;m<16;m++)RedTable[m]=0x00; 
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
       // for(m=0;m<16;m++)BlueTable[m]=0x00; 
        for(m=0;m<21;m++)
        {       
                for(n=0;n<15;n++)
                {
                	RedTable[n]=RedTable[n+1];
                  BlueTable[n]=BlueTable[n+1];
                  if(BeginRcvFlag)break;
                }
                RedTable[15]=j[m];
                BlueTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
//---------------------------------------------------------------------------------------------
void WhiteWaveBackwardChase(unsigned char Spd)
{
				unsigned char m,n,k; 
        unsigned char j[16]={1,2,3,4,6,9,12,16,16,12,9,6,4,3,2,1};
        for(m=0;m<16;m++){RedTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00; if(BeginRcvFlag)break;}
        for(m=0;m<21;m++)
        {       
                for(n=0;n<15;n++)
                {
                	 RedTable[n]=RedTable[n+1];
                	 GreenTable[n]=GreenTable[n+1];
                	 BlueTable[n]=BlueTable[n+1];
                	 if(BeginRcvFlag)break;
                }
                RedTable[15]=j[m];
                GreenTable[15]=j[m];
                BlueTable[15]=j[m];
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
        }    		
}
//--------------------------------------------------------------------------------------------------
void ThreeColorWaveBackwardChase(unsigned char Spd)
{
 
	unsigned char m,n,k,r,g,b; 
	unsigned char j1[16]={15,10,6,2,1,0,0,0,0,0,0,0,0,0,0,0};
	unsigned char j2[16]={0,0,0,0,0,0,15,10,6,2,1,0,0,0,0,0};
	unsigned char j3[16]={0,0,0,0,0,0,0,0,0,0,0,15,10,6,2,1};
	for(m=0;m<16;m++)
	{
		 RedTable[m]=j1[m];
		 GreenTable[m]=j2[m];
		 BlueTable[m]=j3[m];
		 if(BeginRcvFlag)break;
	}
        for(m=0;m<100;m++)
        {       
                        r=RedTable[0];
                        g=GreenTable[0];
                        b=BlueTable[0];
                        for(n=0;n<15;n++)
                        {
                                RedTable[n]=RedTable[n+1]; 
                                GreenTable[n]=GreenTable[n+1];
                                BlueTable[n]=BlueTable[n+1];
                                if(BeginRcvFlag)break;
                        }
                        RedTable[15]=r;
                        GreenTable[15]=g;
                        BlueTable[15]=b;
                  for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                  if(BeginRcvFlag)break;
        }    					
}
//////////////////////////////////////////////////////////////////////////////////////////////////////// 
//ÏòÇ°Ìø»¬ÐÐ
//-----------------------------------------------------------------------------------------------------
void RedForwardJump(unsigned char Spd)
{
	unsigned char m,n,k;
	for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
        for(k=0;k<Spd;k++)delay_us(200); 
        RedTable[15]=15;
	for(m=0;m<16;m++)
	{
                for(n=0;n<15;n++){RedTable[n]=RedTable[n+1];if(BeginRcvFlag)break;}
                for(k=0;k<Spd;k++){delay_us(20);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
}            
//---------------------------------------------------------------------------------------------------- 
void GreenForwardJump(unsigned char Spd)
{
	unsigned char m,n,k;
	for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
        for(k=0;k<Spd;k++)delay_us(200);
        GreenTable[15]=15;
	for(m=0;m<16;m++)
	{
                for(n=0;n<15;n++){GreenTable[n]=GreenTable[n+1];if(BeginRcvFlag)break;}
                for(k=0;k<Spd;k++){delay_us(20);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
}
//---------------------------------------------------------------------------------------------------- 
void BlueForwardJump(unsigned char Spd)
{
	unsigned char m,n,k;
	for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
  for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
  for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
  BlueTable[15]=15;
	for(m=0;m<16;m++)
	{
                for(n=0;n<15;n++){BlueTable[n]=BlueTable[n+1];if(BeginRcvFlag)break;}
                for(k=0;k<Spd;k++){delay_us(20);}
                if(BeginRcvFlag)break;
	}
}   
 //-----------------------------------------------------------------------------------------------------
void YellowForwardJump(unsigned char Spd)
{
	unsigned char m,n,k;
for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;if(BeginRcvFlag)break;}
for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;if(BeginRcvFlag)break;}
for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;if(BeginRcvFlag)break;}
  for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
  RedTable[15]=15;
  GreenTable[15]=15;
	for(m=0;m<16;m++)
	{
                for(n=0;n<15;n++)
                {
                	RedTable[n]=RedTable[n+1];
                	GreenTable[n]=GreenTable[n+1];
                	if(BeginRcvFlag)break;
                }
                for(k=0;k<Spd;k++){delay_us(20);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
}                                
 //-----------------------------------------------------------------------------------------------------
void CyanForwardJump(unsigned char Spd)
{
	unsigned char m,n,k;
	for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
        for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
        BlueTable[15]=15;
        GreenTable[15]=15;
	for(m=0;m<16;m++)
	{ 
                for(n=0;n<15;n++)
                {
                	BlueTable[n]=BlueTable[n+1];
                	GreenTable[n]=GreenTable[n+1];
                	if(BeginRcvFlag)break;
                }
                for(k=0;k<Spd;k++){delay_us(20);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
}
 //-----------------------------------------------------------------------------------------------------
void PurpleForwardJump(unsigned char Spd)
{
	unsigned char m,n,k;
	for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
  for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
  for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
  RedTable[15]=15;
  BlueTable[15]=15;
	for(m=0;m<16;m++)
	{
                for(n=0;n<15;n++)
                {
                	RedTable[n]=RedTable[n+1];
                	BlueTable[n]=BlueTable[n+1];
                	if(BeginRcvFlag)break;
                }
                for(k=0;k<Spd;k++){delay_us(20);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
}                                       
 //-----------------------------------------------------------------------------------------------------
void WhiteForwardJump(unsigned char Spd)
{
	unsigned char m,n,k;
	for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
  for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
  for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
  RedTable[15]=15;
  BlueTable[15]=15;
  GreenTable[15]=15;
	for(m=0;m<16;m++)
	{
                for(n=0;n<15;n++)
                {
                	RedTable[n]=RedTable[n+1];
                	GreenTable[n]=GreenTable[n+1];
                	BlueTable[n]=BlueTable[n+1];
                	if(BeginRcvFlag)break;
                }
                for(k=0;k<Spd;k++){delay_us(20);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//ÏòºóÌø»¬ÐÐ
//-----------------------------------------------------------------------------------------------------
void RedBackwardJump(unsigned char Spd)
{
	unsigned char m,n,k;	
	
	for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
        for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
        RedTable[0]=15;
	for(m=0;m<16;m++)
	{
                for(n=15;n>0;n--)
                {
                        RedTable[n]=RedTable[n-1];
                        if(BeginRcvFlag)break;
                }
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
}
//-----------------------------------------------------------------------------------------------------
void GreenBackwardJump(unsigned char Spd)
{
	unsigned char m,n,k;	
	
	for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
        for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
        for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
        GreenTable[0]=15;
	for(m=0;m<16;m++)
	{
                for(n=15;n>0;n--)
                {
                        GreenTable[n]=GreenTable[n-1];	
                        if(BeginRcvFlag)break;
                }
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
} 
//-----------------------------------------------------------------------------------------------------
void BlueBackwardJump(unsigned char Spd)
{
	unsigned char m,n,k;	
	
	for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
  for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
  for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
  BlueTable[0]=15;
	for(m=0;m<16;m++)
	{
                for(n=15;n>0;n--){BlueTable[n]=BlueTable[n-1];if(BeginRcvFlag)break;}
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
} 
//-----------------------------------------------------------------------------------------------------
void YellowBackwardJump(unsigned char Spd)
{
	unsigned char m,n,k;	
	
	for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
  for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
  for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
  RedTable[0]=15;
  GreenTable[0]=15;
	for(m=0;m<16;m++)
	{
                for(n=15;n>0;n--)
                {
                	RedTable[n]=RedTable[n-1];
                	GreenTable[n]=GreenTable[n-1];
                	if(BeginRcvFlag)break;
                }
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
}
//-----------------------------------------------------------------------------------------------------
void PurpleBackwardJump(unsigned char Spd)
{
	unsigned char m,n,k;	
	
	for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
  for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
  for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
  BlueTable[0]=15;
  RedTable[0]=15;
	for(m=0;m<16;m++)
	{
                for(n=15;n>0;n--)	
                {
                	RedTable[n]=RedTable[n-1];
                	BlueTable[n]=BlueTable[n-1];
                	if(BeginRcvFlag)break;		
                }
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
}
//-----------------------------------------------------------------------------------------------------
void CyanBackwardJump(unsigned char Spd)
{
	unsigned char m,n,k;	
	
	for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
  for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
  for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
  BlueTable[0]=15;
  GreenTable[0]=15;
	for(m=0;m<16;m++)
	{
                for(n=15;n>0;n--)
                {
                	GreenTable[n]=GreenTable[n-1];
                	BlueTable[n]=BlueTable[n-1];
                	if(BeginRcvFlag)break;
                }	
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
}  
//-----------------------------------------------------------------------------------------------------
void WhiteBackwardJump(unsigned char Spd)
{
	unsigned char m,n,k;	
	
	for(m=0;m<16;m++){BlueTable[m]=0x00;if(BeginRcvFlag)break;}
	for(m=0;m<16;m++){GreenTable[m]=0x00;if(BeginRcvFlag)break;}
  for(m=0;m<16;m++){RedTable[m]=0x00;if(BeginRcvFlag)break;}
  for(k=0;k<Spd;k++){delay_us(200);if(BeginRcvFlag)break;}
  BlueTable[0]=15;
  GreenTable[0]=15;
  RedTable[0]=15;
	for(m=0;m<16;m++)
	{
                for(n=15;n>0;n--)
                {
                	RedTable[n]=RedTable[n-1];
                	GreenTable[n]=GreenTable[n-1];
                	BlueTable[n]=BlueTable[n-1];
                	if(BeginRcvFlag)break;
                }
                for(k=0;k<Spd;k++){delay_us(10);if(BeginRcvFlag)break;}
                if(BeginRcvFlag)break;
	}
} 
   
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void FunctionListTable(unsigned char FunctionNumber,unsigned char Speed)
 {
 		switch(FunctionNumber)
 		{
 					case 0:													Clr();																									break;							
 					case 1:													StaticRed();																						break;
 					case 2:													StaticGreen();																					break;
 					case 3:													StaticBlue();																						break;
 					case 4:													StaticYellow();																					break;
 					case 5:													StaticCyan();																						break;
 					case 6:													StaticPurple();																					break;
 					case 7:													StaticWhite();																					break;
 						
 					case 8:													RedSynchFlash(Speed);   																break;															
 					case 9:													GreenSynchFlash(Speed);   															break;
 					case 10:												BlueSynchFlash(Speed);   																break;
 					case 11:												YellowSynchFlash(Speed);   															break;
 					case 12:												CyanSynchFlash(Speed);   																break;
 					case 13:												PurpleSynchFlash(Speed);  				 											break;
 					case 14:												WhiteSynchFlash(Speed);   															break;
 						
 					case 15:												RedSynchSmooth(Speed);																	break;
 					case 16:												GreenSynchSmooth(Speed);																break;
 					case 17:												BlueSynchSmooth(Speed);																	break;
 					case 18:												YellowSynchSmooth(Speed);																break;
 					case 19:												CyanSynchSmooth(Speed);																	break;
 					case 20:												PurpleSynchSmooth(Speed);																break;
 					case 21:												WhiteSynchSmooth(Speed);																break;
 						
 					case 22:												RedDimToBrightForwardChase(Speed);  										break;
 					case 23:												GreenDimToBrightForwardChase(Speed);  									break;
 					case 24:												BlueDimToBrightForwardChase(Speed);  										break;
 					case 25:												YellowDimToBrightForwardChase(Speed);  									break;
 					case 26:												CyanDimToBrightForwardChase(Speed);  										break;
 					case 27:												PurpleDimToBrightForwardChase(Speed); 									break;
 					case 28:												WhiteDimToBrightForwardChase(Speed); 										break;
 						
 					case 29:												RedCometForward(Speed);																	break;
 					case 30:												GreenCometForward(Speed);																break;
 					case 31:												BlueCometForward(Speed);																break;
 					case 32:												YellowCometForward(Speed);															break;
 					case 33:												CyanCometForward(Speed);																break;
 					case 34:												PurpleCometForward(Speed);															break;
 					case 35:												WhiteCometForward(Speed);																break;
 						
 					case 36:												RedCometBackward(Speed);																break;
 					case 37:												GreenCometBackward(Speed);															break;
 					case 38:												BlueCometBackward(Speed);																break;
 					case 39:												YellowCometBackward(Speed);															break;
 					case 40:												CyanCometBackward(Speed);																break;
 					case 41:												PurpleCometBackward(Speed);															break;
 					case 42:												WhiteCometBackward(Speed);															break;
 						
 					case 43:												RedWaveForwardChase(Speed);															break;
 					case 44:												GreenWaveForwardChase(Speed);														break;
 					case 45:												BlueWaveForwardChase(Speed);														break;
 					case 46:												YellowWaveForwardChase(Speed);													break;
 					case 47:												CyanWaveForwardChase(Speed);														break;
 					case 48:												PurpleWaveForwardChase(Speed);													break;
 					case 49:												WhiteWaveForwardChase(Speed);														break;
 						
 					case 50:												RedWaveBackwardChase(Speed);														break;
 					case 51:												GreenWaveBackwardChase(Speed);													break;
 					case 52:												BlueWaveBackwardChase(Speed);														break;
 					case 53:												YellowWaveBackwardChase(Speed);													break;
 					case 54:												CyanWaveBackwardChase(Speed);														break;
 					case 55:												PurpleWaveBackwardChase(Speed);													break;
 					case 56:												WhiteWaveBackwardChase(Speed);													break;				
 					case 57:												ThreeColorWaveBackwardChase(Speed);											break;
 						
 					case 58:												RedForwardJump(Speed);																	break;
 					case 59:												GreenForwardJump(Speed);																break;
 					case 60:												BlueForwardJump(Speed);																	break;
 					case 61:												YellowForwardJump(Speed);																break;
 					case 62:												CyanForwardJump(Speed);																	break;
 					case 63:												PurpleForwardJump(Speed);																break;
 					case 64:												WhiteForwardJump(Speed);																break;
 						
 					case 65: 												RedBackwardJump(Speed);																	break;
 					case 66:												GreenBackwardJump(Speed);																break;
 					case 67:												BlueBackwardJump(Speed);																break;
 					case 68:												YellowBackwardJump(Speed);															break;
 					case 69:												CyanBackwardJump(Speed);																break;
 					case 70:												PurpleBackwardJump(Speed);															break;
 					case 71:												WhiteBackwardJump(Speed);																break;
 						
 					case 72:												RedDimToBrightBackwardChase(Speed);											break;
 					case 73:												GreenDimToBrightBackwardChase(Speed);										break;
 					case 74:												BlueDimToBrightBackwardChase(Speed);										break;
 					case 75:												YellowDimToBrightBackwardChase(Speed);									break;
 					case 76:												CyanDimToBrightBackwardChase(Speed);										break;
 					case 77:												PurpleDimToBrightBackwardChase(Speed);									break;
 					case 78:												WhiteDimToBrightBackwardChase(Speed);										break;	
 					case 79:												SevenSynchFlash(Speed);																	break;	
 		}		
 }  
 