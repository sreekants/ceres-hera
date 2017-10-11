# Ceres (Hera-Release)
This is a demo package of the Hera release of the [Ceres farm operating system](https://www.openhub.net/p/ceres-os). 

The Ceres project is an exploratory experiment to figure out a low-cost turnkey infrastructure in a national scale can avert the scourge of climate change in the poorest of countries around the world. Although this is an Indian story, there is a resonance of the same challenges across Equatorial & Sub-Saharan Africa, South-Asia, Latin America & South East Asia.

## Introduction
The Hera release is an exploratory experiment to figure out what kind of a low-cost IoT infrastructure is required to delopy AI-based precision farming across farms in emerging countries. The experiments in architecture, platforms & technologies here, are the intial steps toward a highly distributed, remotely deployable IoT host operating system running on a broad set of real-time OS (including Arduino, RTOS, Windows-Embedded & Linux), spread across farms in the emerging countries.

### Related Reading
#### Artificial Intelligence & IoT
* [How sensors, robotics and artificial intelligence will transform agriculture](https://www.forbes.com/sites/jenniferhicks/2017/03/19/how-sensors-robotics-and-artificial-intelligence-will-transform-agriculture/#631a05cf384b)
* [Can artiticial intelligence help feed the world](https://www.forbes.com/sites/themixingbowl/2017/09/05/can-artificial-intelligence-help-feed-the-world/#296b806c46db)
* [When artificial intelligence met peach](www.bbc.co.uk/news/world-asia-china-41479282)
* [Drones, tractor hacks and robotic sprayers: the technology of farming](www.cbc.ca/news/technology/farming-technology-advances-1.4290569)
* [John Deere is plowing IoT into its farm equipment](https://www.networkworld.com/article/3071340/internet-of-things/john-deere-is-plowing-iot-into-its-farm-equipment.html)
* [A Skunk Works with tractors: Inside John Deere’s IoT-innovation unit](https://www.networkworld.com/article/3198744/internet-of-things/a-skunk-works-with-tractors-inside-john-deere-s-high-tech-iot-innovation-unit.html)

#### Food Secuity & Impact of Climate Change
* [Our dying rivers](http://isha.sadhguru.org/rally-for-rivers/our-dying-rivers/)
* [After 47 years, water level hits rock bottom at KRS](http://m.deccanherald.com/articles.php?name=http%3A%2F%2Fwww.deccanherald.com%2Fcontent%2F572645%2Fafter-47-years-water-level.html)
* [Depleting water level in Neyyar dam raises concerns](https://timesofindia.indiatimes.com/city/thiruvananthapuram/Depleting-water-level-in-Neyyar-dam-raises-concern/articleshow/56262674.cms)

## Objective
Hera is a feasibility study for Zeus, that answers the following questions:
* Is it possible to automate a remote rural farm entirely using IoT?
* It it possible to remotely administer, upgrade and reprovision it entirely through mobile phone or internet?
* Is it possible to automate a farm at $0.1/sqft?

## Conclusions
We are now optimistic that the objectives can be achieved. However, we will need to significantly modify our original ar

## Status
### Phase 1 - Skunkworks/Technology Evaluation (Aug-Oct 2017)

*Status - Architecture unsatisfactory.*

A prototypical version of Hera has been developed as part of Ceres (version 0.3). This however has not achieved our design goals. The implementation of Ceres on ESP8266, our target platform needs to be significantly optimized. Memory limitations on the ESP8266 significantly curtails the implementation of our solution. We are looking into topograpical, architectural and/or platform (move to ESP32) changes to work around the limitations. 


### Phase 2 - Initial Implementation (Jan-Apr 2018)

## Package
Included in this package are: 
* src/nodeos - Sourcecode for the final Ceres sketch (generated from base sourcecode on sourceforge into a single file ceres.node.h). 
* bin/appemu - RAD development tool for Ceres LUA applications (individual applications in lua files in the directory).

## Concept 
![Concept diagram](https://ceres-os.sourceforge.io/docs/releases/images/Concept-Diagram-small.png)

## Project Outline
For an outline of the project description, checkout the wiki page on [sourceforge](https://sourceforge.net/p/ceres-os/wiki/Home/).



## Releated Links
* [Ceres Farm Operating System - Project Profile](https://www.openhub.net/p/ceres-os)
* [Empact Foundation Class Library - Project Profile](https://www.openhub.net/p/empact)


