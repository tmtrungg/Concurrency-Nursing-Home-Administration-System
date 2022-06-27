# Concurrency Nursing Home Administration System

## Background:

Nursing home – the very popular terms to all kinds of people with describe as a modern facility taking care of old or disable people. The nursing home system is widely applied to every developed country in the world to provide better heath care to old/disable with their research methods and technologies and become an industry to growth with moral purposes.

Despite all the problems that many other industries in developing country faced such as money, land to build places, problem on HR, the biggest issue that is preventing nursing home become a reliable service in Vietnam is that: unscientific and passive reacting in arrangement of patient taking care:

- When the patient number is much larger than the nurse, make it insufficient and hard to control/arrange them to take care for patient.
- Passive in reacting with request, when there’s no technology to logically optimize the arrangement of nurse to patient that has a problem.
- Hard to update and control which worker is busy and free, leads to unable to using people effectively and can guarantee caring quality.

## Project overview:
A system program that can dynamically control the availability and location of nurses ( workers ) and patient then optimizing the process of automatically arrange the available and nearest nurse to a particular patient with a request (the request from the patient is going to be sent to the system). The system must be capable of:

- Using triggering embedded sensor to collect the real time request sent from the patient’s devices to have the best response.
- Arranging optimizing and logically in pairing workers-patient to serve them with the request in a scale of 1000 patient and 1000 worker with openMP version ( for a 1 strong memory PCs system ) or MPI ( for a distributed multiple PC system ).
- Dynamically multitasking of : updating worker history, Ford-Fulkerson algorithm and send message of the work sheet ( patient name, patient’s place, nearest path to patient’s location,... ) in the same time using mentioned MPI or openMP ( 2 code options based on different system ).

## Design principles:
### Cost

The system is the replacement for the expensive control and administration facility of the nursing home – which can hardly get in the low- investment level of the industry. Every nursing home which planning to applying the system only need to have a strong enough computer, and an Arduino for each of their patient ( with 3 set up PIR sensor ), which is very cheap in average for an effective system to enhance the nurse work and nursing home quality on serving patient.

### Real-time response
The system guarantee the soft real-time principles – automatically send an available nurse to the requested patient right after one of them are with the precision in large scale ( for example 50 patient request in the same time, the available nurse will be processed to be arranged in correct order for 50 of them without latency, the available status of nurse will also be updated by their phone to the system in every loop to make sure the nurses availability is also real-time ).

### Multithreading and Distributed system
The multithreading and distributed programming structure provide a solution in decomposition method. The tasks will be separated for different unit to process ( threads/machines ) to push the efficiency, decrease time complexity and nurse serving quality in handling big dynamic data that constantly updating like the request system.

### Component-based simple structure to use, manage and upgrade
The Component-based structure of data flow and system set up ( using Arduino and simple C++ terminal ) gives the solution the advantages of easy to build part-by-part, easy to use and easy to upgrade/adding more features into specific function group.

## Hardware:
- The Computer system to run the main code.
- Arduino and 3 set up PIR sensor for each patient in their room to make a request.
- Phone for every nurse ( to receive working message, shortest way to the patient’s location and update their availability ).

## Software:
- C++ : Use to build the main code that run during the system work (with MPI/openMP).
- IFTTT : Use to transport Arduino’s data from patients into total sheet (google sheet).
- Google API : Use to update google sheet to the system and the C++ code will work on it.

## Design Pattern
(blank for now)

## Project running demonstration:
https://youtu.be/Tlq4uzVe-Dk
