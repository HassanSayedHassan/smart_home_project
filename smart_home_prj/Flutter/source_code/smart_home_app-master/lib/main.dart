import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';
import 'package:flutter_screenutil/flutter_screenutil.dart';
import 'package:servo_app/connection.dart';
import 'package:servo_app/pages/Home_page.dart';
import 'package:servo_app/pages/log_in_page.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return ScreenUtilInit(
      designSize: Size(2005, 3564),
      builder: () => MaterialApp(
        builder: (context, widget) {
          ScreenUtil.setContext(context);
          return MediaQuery(
            //Setting font does not change with system font size
            data: MediaQuery.of(context).copyWith(textScaleFactor: 1.0),
            child: widget,
          );
        },
        debugShowCheckedModeBanner: false,
        title: 'SMART HOME',
        theme: ThemeData(
            primarySwatch: Colors.blue,
            brightness: Brightness.dark,
            fontFamily: "POORICH"
        ),
        home: FutureBuilder(
          future: FlutterBluetoothSerial.instance.requestEnable(),
          builder: (context, future) {
            if (future.connectionState == ConnectionState.waiting) {
              return Scaffold(
                body: Container(
                  height: double.infinity,
                  child: Center(
                    child: Icon(
                      Icons.bluetooth_disabled,
                      size: 200.0,
                      color: Colors.blue,
                    ),
                  ),
                ),
              );
            } else {
              return LogInPage();
            }
          },
          // child: MyHomePage(title: 'Flutter Demo Home Page'),
        ),
      ),
    );
  }
}

class Home extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SafeArea(
        child: Scaffold(
      appBar: AppBar(
        title: Text('Connection'),
      ),
      body: SelectBondedDevicePage(
        onCahtPage: (device1) {
          BluetoothDevice device =BluetoothDevice(
            name: "HC-05",
            address: "98:D3:11:FC:27:61",
            bondState: BluetoothBondState.bonded,
            isConnected: true,
            type: BluetoothDeviceType.classic
          );
          print("Selecteddevice ${device.name}");
          print("Selecteddevice ${device.address}");
          print("Selecteddevice ${device.bondState}");
          print("Selecteddevice ${device.isConnected}");
          print("Selecteddevice ${device.type}");
         // Navigator.push(context, MaterialPageRoute(builder: (context) {return ChatPage(server: device);},),);
        },
      ),
    ));
  }
}
