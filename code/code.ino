#define trig1 3 

#define echo1 2 

#define led1 10  

#define led2 9 

#define led3 8 

#define led4 11 

#define led5 12 

#define led6 13 

unsigned long thoigian1; 

//unsigned long thoigian2;  

int dem,t,t1,t2; 

int kccb1bandau; 

//int kccb2bandau; 

int khoangcach1; 

//int khoangcach2;           

int songuoi; 

String hangdoi = ""; 

int timeoutcounter=0; 

void setup() { 

  // put your setup code here, to run once: 

  pinMode(trig1, OUTPUT); 

  pinMode(echo1, INPUT);  

  pinMode(led1, OUTPUT); 

  pinMode(led2, OUTPUT); 

  pinMode(led3, OUTPUT); 

  pinMode(led4, OUTPUT); 

  pinMode(led5, OUTPUT); 

  pinMode(led6, OUTPUT); 

  Serial.begin(9600); 

  songuoi=0; 

  delay(100); 

  dokhoangcach1(); 

  kccb1bandau=khoangcach1; 

  t1 = 10; 

  

} 

 

void loop() { 

  // put your main code here, to run repeatedly: 

   khoangcach1 = 0; 

   dokhoangcach1(); 

   if (khoangcach1<kccb1bandau - 50 ){ 

     songuoi++; 

     Serial.print("so nguoi la ");Serial.println(songuoi); 

   } 

   //Serial.println(songuoi); 

   delay(100); 

     t = millis() / 1000; 

   if(t >= t1){ 

       if(dem == 0){ 

         dem = 1 ; 

         digitalWrite(led3, LOW); 

         digitalWrite(led1, HIGH); 

         digitalWrite(led6, HIGH); 

         digitalWrite(led5, LOW); 

         t2 =   round((songuoi*20)/(songuoi + 5) ); 

         if(t2 > 17){  

           t2 = 17; 

           } 

         Serial.print("den xanh trong ");Serial.print(t2);Serial.println(" giay"); 

         delay(100); 

         t1 = t1 + t2; 

         songuoi = 0; 

       }  

       else if (dem == 1){ 

         dem = 2; 

         digitalWrite(led1, LOW); 

         digitalWrite(led2, HIGH); 

         Serial.println("den vang trong 3 giay "); 

         delay(100); 

         t1 = t1 + 3; 

         } 

     else if (dem == 2){ 

         dem = 3 ; 

         digitalWrite(led2, LOW); 

         digitalWrite(led3, HIGH); 

         digitalWrite(led4, HIGH);  

         digitalWrite(led6, LOW) ;          

         t2 = 20 - t2; 

         Serial.print("den do trong ");Serial.print(t2);Serial.println(" giay"); 

         delay(100); 

         t1 = t1 + t2 -3 ; 

     } 

     else if (dem == 3){ 

         dem = 0 ; 

         digitalWrite(led4, LOW); 

         digitalWrite(led5, HIGH); 

         t1 = t1 + 3;          

     }   

   } 

} 

void dokhoangcach1() 

{ 



