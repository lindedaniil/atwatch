# atwatch
Группа:
3530904/80104

Участники:

Квашнин Артём

Линде Даниил

Этапы:
1) Определение проблемы:

	 Данный проект стремится улучшить качество жизни пользователя, реализуя полный функционал смарт-часов. Используя данное устройство, пользователь может использовать 		 базовый     функционал наручных часов(просмотр времени, секундомер, таймер) и получать информацию о температуре и давлении окружающей среды и данные с акселерометра.  
2) Требования к программному обеспечению:

	2.1) Пользовательские требования:
	- Устройство должно реализовывать весь базовый функционал часов такой как: счет текущего времени, возможность использовать секундомер и таймер.
	- Устройство должно давать пользователю возможность получать данные с датчиков по запросу.
	- Устройство должно иметь пользовательское меню для ориентации в функционале.
	- Управление должно осуществляться посредством нажатия кнопок.
	- Информация должна выводиться на дисплей.
	
	2.2) Системные требования:
	- Прошивка должна работать для микроконтроллера avr ATMEGA1284.
	
3) Разработка архитектуры:

	3.1) System Context diagram:
  
  
	![Diagram1](https://user-images.githubusercontent.com/55754551/97785046-cd285300-1bb3-11eb-8cb6-e7b8b7948353.png)
	
	3.2) Container diagram:
  
  ![Diagram2](https://user-images.githubusercontent.com/55754551/97785109-1b3d5680-1bb4-11eb-939d-25929951c273.png)
  
  4)UML диаграммы классов:
  ![diagramUML2](https://user-images.githubusercontent.com/55754551/97790166-5ac96a00-1bd7-11eb-8a93-8df94568158a.png)
  ![diagramUML3](https://user-images.githubusercontent.com/55754551/97790167-5e5cf100-1bd7-11eb-8a4a-6971b5d07034.png)
  ![diagramUML4](https://user-images.githubusercontent.com/55754551/97790173-63ba3b80-1bd7-11eb-8c8a-0884d4c7d945.png)
  5) Тестирование:
  
    Тестирование осуществлялось с использованием фреймворка Sput Unit Testing framework.
    
    В /atwatch/blob/master/src/Tests/tests.cpp написаны три функции симулирующие нажатия кнопок. В последнем методе происходит запуск этих функций.
    
    sput_start_testing - этот макрос подготавливает структуры фреймворка. Должен быть вызван прежде остальных.
    
    sput_enter_suite("buttons") - подготавливает именнованный набор тестов
    
    sput_run_test(function_name) - прогоняет тестовый случай
    
    sput_finish_testing() - генерирует статистику
    
    sput_get_return_value() - возвращает статус код тестов: EXIT_SUCCESS при успешном прохождении всех тестовых сценариев, EXIT_FAILURE - в любом другом случает
    
    sput_fail_unless(condition, description) - получает условие и описание проверки, возвращает bool значение.
	
6) Сборка из консоли:

	6.1)Компиляция:
	
	   hex: avr-gcc -c -std=gnu99 -Os -Wall -ffunction-sections -fdata-sections -mmcu=m1284p -DF_CPU=12000000 
	
	6.2)Загрузка:
	
	   hex: avrdude -C /avrdude/avrdude.conf -p m328p -c /dev/ttyusbN -b 19600 -P COM0 -U flash:w:atwatch.ihex:i
	
	6.3)Запуск тестов:
	
	   Тесты запускаются автоматически после  загрузки  в COM-порт.
	
    
    
      

