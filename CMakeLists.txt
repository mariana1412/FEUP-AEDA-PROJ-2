cmake_minimum_required(VERSION 3.15)
project(projeto)

set(CMAKE_CXX_STANDARD 14)

add_executable(projeto main.cpp Classes/Base.cpp Classes/Location.h Classes/Location.cpp Classes/Order.cpp Classes/Order.h Classes/Person.cpp Classes/Person.h Classes/Product.cpp Classes/Product.h Classes/Restaurant.cpp Classes/Restaurant.h Classes/Time.cpp Classes/Time.h Classes/Vehicle.cpp Classes/Vehicle.h Functions/Verification_Inputs.cpp Functions/Verification_Inputs.h Functions/utils.cpp Functions/utils.h Functions/ReadingFiles.h Functions/ReadingFiles.cpp Functions/Clients_functions.cpp Functions/Clients_functions.h Functions/StringConverters.cpp Functions/StringConverters.h Functions/WriteToFile.cpp Functions/WriteToFile.h Functions/Exceptions.h Functions/Menus.h Functions/Menus.cpp Functions/Restaurants_functions.cpp Functions/Restaurants_functions.h Functions/Employees_functions.cpp Functions/Employees_functions.h Functions/Order_functions.cpp Functions/Order_functions.h Functions/Visualize_Information.cpp Functions/Visualize_Information.h Functions/ProfitsCalculation.cpp Functions/ProfitsCalculation.h Classes/Company.cpp Classes/Company.h)
