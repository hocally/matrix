#include <ESP8266WiFi.h>

static unsigned char Font5x7[][93] = {
  {0x00, 0x00, 0x00, 0x00, 0x00},// (space)
  {0x00, 0x00, 0x5F, 0x00, 0x00},// !
  {0x00, 0x07, 0x00, 0x07, 0x00},// "
  {0x14, 0x7F, 0x14, 0x7F, 0x14},// #
  {0x24, 0x2A, 0x7F, 0x2A, 0x12},// $
  {0x23, 0x13, 0x08, 0x64, 0x62},// %
  {0x36, 0x49, 0x55, 0x22, 0x50},// &
  {0x00, 0x05, 0x03, 0x00, 0x00},// '
  {0x00, 0x1C, 0x22, 0x41, 0x00},// (
  {0x00, 0x41, 0x22, 0x1C, 0x00},// )
  {0x08, 0x2A, 0x1C, 0x2A, 0x08},// *
  {0x08, 0x08, 0x3E, 0x08, 0x08},// +
  {0x00, 0x50, 0x30, 0x00, 0x00},// ,
  {0x08, 0x08, 0x08, 0x08, 0x08},// -
  {0x00, 0x60, 0x60, 0x00, 0x00},// .
  {0x20, 0x10, 0x08, 0x04, 0x02},// /
  {0x3E, 0x51, 0x49, 0x45, 0x3E},// 0
  {0x00, 0x42, 0x7F, 0x40, 0x00},// 1
  {0x42, 0x61, 0x51, 0x49, 0x46},// 2
  {0x21, 0x41, 0x45, 0x4B, 0x31},// 3
  {0x18, 0x14, 0x12, 0x7F, 0x10},// 4
  {0x27, 0x45, 0x45, 0x45, 0x39},// 5
  {0x3C, 0x4A, 0x49, 0x49, 0x30},// 6
  {0x01, 0x71, 0x09, 0x05, 0x03},// 7
  {0x36, 0x49, 0x49, 0x49, 0x36},// 8
  {0x06, 0x49, 0x49, 0x29, 0x1E},// 9
  {0x00, 0x36, 0x36, 0x00, 0x00},// :
  {0x00, 0x56, 0x36, 0x00, 0x00},// ;
  {0x00, 0x08, 0x14, 0x22, 0x41},// <
  {0x14, 0x14, 0x14, 0x14, 0x14},// =
  {0x41, 0x22, 0x14, 0x08, 0x00},// >
  {0x02, 0x01, 0x51, 0x09, 0x06},// ?
  {0x32, 0x49, 0x79, 0x41, 0x3E},// @
  {0x7E, 0x11, 0x11, 0x11, 0x7E},// A
  {0x7F, 0x49, 0x49, 0x49, 0x36},// B
  {0x3E, 0x41, 0x41, 0x41, 0x22},// C
  {0x7F, 0x41, 0x41, 0x22, 0x1C},// D
  {0x7F, 0x49, 0x49, 0x49, 0x41},// E
  {0x7F, 0x09, 0x09, 0x01, 0x01},// F
  {0x3E, 0x41, 0x41, 0x51, 0x32},// G
  {0x7F, 0x08, 0x08, 0x08, 0x7F},// H
  {0x00, 0x41, 0x7F, 0x41, 0x00},// I
  {0x20, 0x40, 0x41, 0x3F, 0x01},// J
  {0x7F, 0x08, 0x14, 0x22, 0x41},// K
  {0x7F, 0x40, 0x40, 0x40, 0x40},// L
  {0x7F, 0x02, 0x04, 0x02, 0x7F},// M
  {0x7F, 0x04, 0x08, 0x10, 0x7F},// N
  {0x3E, 0x41, 0x41, 0x41, 0x3E},// O
  {0x7F, 0x09, 0x09, 0x09, 0x06},// P
  {0x3E, 0x41, 0x51, 0x21, 0x5E},// Q
  {0x7F, 0x09, 0x19, 0x29, 0x46},// R
  {0x46, 0x49, 0x49, 0x49, 0x31},// S
  {0x01, 0x01, 0x7F, 0x01, 0x01},// T
  {0x3F, 0x40, 0x40, 0x40, 0x3F},// U
  {0x1F, 0x20, 0x40, 0x20, 0x1F},// V
  {0x7F, 0x20, 0x18, 0x20, 0x7F},// W
  {0x63, 0x14, 0x08, 0x14, 0x63},// X
  {0x03, 0x04, 0x78, 0x04, 0x03},// Y
  {0x61, 0x51, 0x49, 0x45, 0x43},// Z
  {0x00, 0x00, 0x7F, 0x41, 0x41},// [
  {0x02, 0x04, 0x08, 0x10, 0x20},// "\"
  {0x41, 0x41, 0x7F, 0x00, 0x00},// ]
  {0x04, 0x02, 0x01, 0x02, 0x04},// ^
  {0x40, 0x40, 0x40, 0x40, 0x40},// _
  {0x00, 0x01, 0x02, 0x04, 0x00},// `
  {0x20, 0x54, 0x54, 0x54, 0x78},// a
  {0x7F, 0x48, 0x44, 0x44, 0x38},// b
  {0x38, 0x44, 0x44, 0x44, 0x20},// c
  {0x38, 0x44, 0x44, 0x48, 0x7F},// d
  {0x38, 0x54, 0x54, 0x54, 0x18},// e
  {0x08, 0x7E, 0x09, 0x01, 0x02},// f
  {0x08, 0x14, 0x54, 0x54, 0x3C},// g
  {0x7F, 0x08, 0x04, 0x04, 0x78},// h
  {0x00, 0x44, 0x7D, 0x40, 0x00},// i
  {0x20, 0x40, 0x44, 0x3D, 0x00},// j
  {0x00, 0x7F, 0x10, 0x28, 0x44},// k
  {0x00, 0x41, 0x7F, 0x40, 0x00},// l
  {0x7C, 0x04, 0x18, 0x04, 0x78},// m
  {0x7C, 0x08, 0x04, 0x04, 0x78},// n
  {0x38, 0x44, 0x44, 0x44, 0x38},// o
  {0x7C, 0x14, 0x14, 0x14, 0x08},// p
  {0x08, 0x14, 0x14, 0x18, 0x7C},// q
  {0x7C, 0x08, 0x04, 0x04, 0x08},// r
  {0x48, 0x54, 0x54, 0x54, 0x20},// s
  {0x04, 0x3F, 0x44, 0x40, 0x20},// t
  {0x3C, 0x40, 0x40, 0x20, 0x7C},// u
  {0x1C, 0x20, 0x40, 0x20, 0x1C},// v
  {0x3C, 0x40, 0x30, 0x40, 0x3C},// w
  {0x44, 0x28, 0x10, 0x28, 0x44},// x
  {0x0C, 0x50, 0x50, 0x50, 0x3C},// y
  {0x44, 0x64, 0x54, 0x4C, 0x44},// z
  {0x00, 0x08, 0x36, 0x41, 0x00},// {
  {0x00, 0x00, 0x7F, 0x00, 0x00},// |
  {0x00, 0x41, 0x36, 0x08, 0x00},// }
};

const char* ssid = "UofM-Guest";
const char* password = "";
const char* host = "api.thingspeak.com";
const char* keys[][11] = {
  {"LA7JEFDWG5ENAO0A", "GGBEGNFQEWPR1JBP"},
  {"5HTRIC1347W3OFQC", "AVLJDO0RGWV0IBCD"},
  {"HSLIP9HZCA5JHJFC", "CXOAXHT4YMEZH24I"},
  {"GOSVRQX3UMR17IQZ", "JW8J3QAZKRID8PQO"},
  {"50GT78F2QK8N44NU", "NPQR8BOQ6F9BBNBI"},
  {"KSQA3UWHKZ0ES6XK", "UUGKDZMI8M7F85GE"},
  {"U4TSU17TY7R0PISS", "1BFDN9SLPVU2UTPC"},
  {"S0FO58KT0TIAUAGI", "0JW6B6JU0575KMBH"},
  {"N4NNY82I97D7MX7Q", "OJQBFESQTLQZ5DRS"},
  {"R9AR12CVSBAN9J02", "W1PKJKUJJDTJCAQ3"},
  {"HZ8PRQNKQV1VX7P3", "M4SKC0BCFO5NK16M"}
};
String payload = "";
/* Order of keys
   0. Stock symbol
   1. Stock price, change, percentage
*/

/* Order of stocks
   0. JNUG
   1. AMD
   2. SNAP
   3. NVDA
   4. TQQQ
   5. VOO
   6. MMM
   7. DIA
   8. AMZN
   9. APPL
   10. TSLA
*/

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
}

void loop()
{
  WiFiClient client;
  for (int i = 0; i < (sizeof(keys) / sizeof(keys[0])); i++)
  {
    for (int j = 0; j < 2; j++)
    {
      //Serial.printf("\n[Connecting to %s ... ", host);
      if (client.connect(host, 80))
      {
        client.print(String("GET /") + "/apps/thinghttp/send_request?api_key=" + keys[i][j] + "\r\n" +
                     "Host:" + host + "\r\n" +
                     "Connection: close\r\n" +
                     "\r\n"
                    );

        //Serial.println("[Response:]");
        while (client.connected())
        {
          if (client.available())
          {
            String line = client.readStringUntil('\n');
            Serial.print(line);
          }
        }
        client.stop();
      }
      else
      {
        Serial.println("connection failed!]");
        client.stop();
      }
      the
      delay(2000);
    }
    Serial.println();
  }
  Serial.println();
}

int charSwitcher (char c) {
  switch (c) {
    case ' ':
      return 0;
      break;
    case '!':
      return 1;
      break;
    case '\"':
      return 2;
      break;
    case '#':
      return 3;
      break;
    case '$':
      return 4;
      break;
    case '%':
      return 5;
      break;
    case '&':
      return 6;
      break;
    case '\'':
      return 7;
      break;
    case '(':
      return 8;
      break;
    case ')':
      return 9;
      break;
    case '*':
      return 10;
      break;
    case '+':
      return 11;
      break;
    case ',':
      return 12;
      break;
    case '-':
      return 13;
      break;
    case '.':
      return 14;
      break;
    case '/':
      return 15;
      break;
    case '0':
      return 16;
      break;
    case '1':
      return 17;
      break;
    case '2':
      return 18;
      break;
    case '3':
      return 19;
      break;
    case '4':
      return 20;
      break;
    case '5':
      return 21;
      break;
    case '6':
      return 22;
      break;
    case '7':
      return 23;
      break;
    case '8':
      return 24;
      break;
    case '9':
      return 25;
      break;
    case ':':
      return 26;
      break;
    case ';':
      return 27;
      break;
    case '<':
      return 28;
      break;
    case '=':
      return 29;
      break;
    case '>':
      return 30;
      break;
    case '?':
      return 31;
      break;
    case '@':
      return 32;
      break;
    case 'A':
      return 33;
      break;
    case 'B':
      return 34;
      break;
    case 'C':
      return 35;
      break;
    case 'D':
      return 36;
      break;
    case 'E':
      return 37;
      break;
    case 'F':
      return 38;
      break;
    case 'G':
      return 39;
      break;
    case 'H':
      return 40;
      break;
    case 'I':
      return 41;
      break;
    case 'J':
      return 42;
      break;
    case 'K':
      return 43;
      break;
    case 'L':
      return 44;
      break;
    case 'M':
      return 45;
      break;
    case 'N':
      return 46;
      break;
    case 'O':
      return 47;
      break;
    case 'P':
      return 48;
      break;
    case 'Q':
      return 49;
      break;
    case 'R':
      return 50;
      break;
    case 'S':
      return 51;
      break;
    case 'T':
      return 52;
      break;
    case 'U':
      return 53;
      break;
    case 'V':
      return 54;
      break;
    case 'W':
      return 55;
      break;
    case 'X':
      return 56;
      break;
    case 'Y':
      return 57;
      break;
    case 'Z':
      return 58;
      break;
    case '[':
      return 59;
      break;
    case '\\':
      return 60;
      break;
    case ']':
      return 61;
      break;
    case '^':
      return 62;
      break;
    case '_':
      return 63;
      break;
    case '`':
      return 64;
      break;
    case 'a':
      return 65;
      break;
    case 'b':
      return 66;
      break;
    case 'c':
      return 67;
      break;
    case 'd':
      return 68;
      break;
    case 'e':
      return 69;
      break;
    case 'f':
      return 70;
      break;
    case 'g':
      return 71;
      break;
    case 'h':
      return 72;
      break;
    case 'i':
      return 73;
      break;
    case 'j':
      return 74;
      break;
    case 'k':
      return 75;
      break;
    case 'l':
      return 76;
      break;
    case 'm':
      return 77;
      break;
    case 'n':
      return 78;
      break;
    case 'o':
      return 79;
      break;
    case 'p':
      return 80;
      break;
    case 'q':
      return 81;
      break;
    case 'r':
      return 82;
      break;
    case 's':
      return 83;
      break;
    case 't':
      return 84;
      break;
    case 'u':
      return 85;
      break;
    case 'v':
      return 86;
      break;
    case 'w':
      return 87;
      break;
    case 'x':
      return 88;
      break;
    case 'y':
      return 89;
      break;
    case 'z':
      return 90;
      break;
    case '{':
      return 91;
      break;
    case '|':
      return 92;
      break;
    case '}':
      return 93;
      break;
  }
}
