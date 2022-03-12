import 'dart:async';
import 'dart:convert';
import 'dart:typed_data';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';
import 'package:servo_app/local_data.dart';
import 'package:servo_app/model/user_model.dart';
import 'package:servo_app/res.dart';
import 'package:syncfusion_flutter_sliders/sliders.dart';
import 'package:flutter_screenutil/flutter_screenutil.dart';

class HomePage extends StatefulWidget {
  final UserModel userModel;

  HomePage(this.userModel);

  @override
  _HomePage createState() => new _HomePage();
}

class _HomePage extends State<HomePage> {
  BluetoothConnection connection;
  BluetoothDevice server = BluetoothDevice(
      name: "HC-05",
      address: "98:D3:11:FC:27:61",
      bondState: BluetoothBondState.bonded,
      isConnected: true,
      type: BluetoothDeviceType.classic);
  String _messageBuffer = '';

  bool isConnecting = true;

  bool get isConnected => connection != null && connection.isConnected;
  bool isDisconnecting = false;

  @override
  void initState() {
    super.initState();

    startConnectionToBluetooth();
  }

  bool isLedOn=false;
  bool isDoorOpen=false;

  @override
  void dispose() {
    if (isConnected) {
      isDisconnecting = true;
      connection.dispose();
      connection = null;
    }

    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
/*      appBar: AppBar(
        title: (isConnecting
            ? Text('Connecting chat to ' + server.name + '...')
            : isConnected
                ? Text('Live chat with ' + server.name)
                : Text('Chat log with ' + server.name))
        ,actions: [
          InkWell(
              onTap: ()
              {
                startConnectionToBluetooth();
              },
              child: Icon(Icons.add))
          ],
      ),*/
      body: SafeArea(
        child: Stack(
          children: [
            Container(
              width: double.infinity,
              height: double.infinity,
              child: Image.asset(
                Res.back_ground,
                fit: BoxFit.cover,
              ),
            ),
            Container(
              padding: EdgeInsets.symmetric(horizontal: 440.w),
              child: Column(
                children: <Widget>[
                  SizedBox(
                    height: 540.h,
                  ),
                  Text(
                    "welcome , ${widget.userModel.userName.split(' ')[0]} \n you can now control \n your office.",
                    style: TextStyle(
                        fontSize: 140.sp, color: Colors.white.withOpacity(0.6)),
                  ),
                  SizedBox(
                    height: 40.h,
                  ),
                  Divider(
                    thickness: 2,
                    color: mainColor,
                  ),
                  SizedBox(
                    height: 40.h,
                  ),
                  Text(
                    "Light",
                    style: TextStyle(
                        fontSize: 140.sp, color: Colors.white.withOpacity(0.6)),
                  ),
                  SizedBox(
                    height: 40.h,
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Column(
                        children: [
                          InkWell(
                            onTap: () {
                              _sendMessage("n");

                              ///Open Led
                              print("Open Led");
                              setState(() {
                                isLedOn=true;
                              });
                            },
                            child: Container(
                              width: 400.w,
                              height: 400.h,
                              child: Image.asset(
                                Res.lamp_opend,
                                fit: BoxFit.fitWidth,
                              ),
                            ),
                          ),
                          SizedBox(height: 10.h,),
                          isLedOn? Container(
                            width: 144.w,
                            height: 144.h,
                            child: Image.asset(
                              Res.correct,
                              fit: BoxFit.fitWidth,
                            ),
                          ):Container(
                            width: 144.w,
                            height: 144.h,
                          ),
                        ],
                      ),
                      Column(
                        children: [
                          InkWell(
                            onTap: () {
                              _sendMessage("f");

                              ///closed Led
                              print("closed Led");
                              setState(() {
                                isLedOn=false;
                              });
                            },
                            child: Container(
                              width: 400.w,
                              height: 400.h,
                              child: Image.asset(
                                Res.lamp_closed,
                                fit: BoxFit.fitWidth,
                              ),
                            ),
                          ),
                          SizedBox(height: 10.h,),
                          isLedOn==false?  Container(
                            width: 144.w,
                            height: 144.h,
                            child: Image.asset(
                              Res.correct,
                              fit: BoxFit.fitWidth,
                            ),
                          ):Container(
                            width: 144.w,
                            height: 144.h,
                          ),
                        ],
                      ),
                    ],
                  ),
                  SizedBox(
                    height: 20.h,
                  ),
                  Text(
                    "Lock",
                    style: TextStyle(
                        fontSize: 140.sp, color: Colors.white.withOpacity(0.6)),
                  ),
                  SizedBox(
                    height: 40.h,
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Column(
                        children: [
                          InkWell(
                            onTap: ()
                            {
                              _sendMessage("r");

                              ///open door
                              print("open door");
                              setState(() {
                                isDoorOpen=true;
                              });
                            },
                            child: Container(
                              width: 400.w,
                              height: 400.h,
                              child: Image.asset(
                                Res.door_open,
                                fit: BoxFit.cover,
                              ),
                            ),
                          ),
                          SizedBox(height: 10.h,),
                          isDoorOpen?Container(
                            width: 144.w,
                            height: 144.h,
                            child: Image.asset(
                              Res.correct,
                              fit: BoxFit.fitWidth,
                            ),
                          ):Container(
                            width: 144.w,
                            height: 144.h,
                          ),
                        ],
                      ),
                      Column(
                        children: [
                          InkWell(
                            onTap: ()
                            {
                              _sendMessage("l");

                              ///close door
                              print("close door");
                              setState(() {
                                isDoorOpen=false;
                              });
                            },
                            child: Container(
                              width: 400.w,
                              height: 400.h,
                              child: Image.asset(
                                Res.door_closed,
                                fit: BoxFit.cover,
                              ),
                            ),
                          ),
                          SizedBox(height: 10.h,),
                          isDoorOpen==false?Container(
                            width: 144.w,
                            height: 144.h,
                            child: Image.asset(
                              Res.correct,
                              fit: BoxFit.fitWidth,
                            ),
                          ):Container(
                            width: 144.w,
                            height: 144.h,
                          ),
                        ],
                      ),
                    ],
                  ),
                ],
              ),
            ),
            isConnected
                ? Positioned(
                    top: 1,
                    left: 1,
                    child: CircleAvatar(
                      radius: 5,
                      backgroundColor: Colors.green,
                    ),
                  )
                : SizedBox(),
            isConnecting
                ? Positioned(
                    top: 10,
                    left: 10,
                    child: CircleAvatar(
                      radius: 20,
                      backgroundColor: Colors.red,
                      child: CircularProgressIndicator(),
                    ),
                  )
                : SizedBox(),
            Positioned(
              top: 5,
              right: 5,
              child: InkWell(
                onTap: () {
                  startConnectionToBluetooth();
                  print("tapped");
                },
                child: CircleAvatar(
                  radius: 30,
                  backgroundColor: Colors.red.withOpacity(0),
                ),
              ),
            ),
            Align(
                alignment: Alignment.bottomCenter,
                child: Container(
                  padding: EdgeInsets.all(150.h),
                  child: Text(
                    "Made    By :     M-H-M",
                    style: TextStyle(
                        color: mainColor,
                        fontSize: 100.sp),
                  ),
                )),
          ],
        ),
      ),
    );
  }

  void _onDataReceived(Uint8List data) {
/*    // Allocate buffer for parsed data
    int backspacesCounter = 0;
    data.forEach((byte) {
      if (byte == 8 || byte == 127) {
        backspacesCounter++;
      }
    });
    Uint8List buffer = Uint8List(data.length - backspacesCounter);
    int bufferIndex = buffer.length;

    // Apply backspace control character
    backspacesCounter = 0;
    for (int i = data.length - 1; i >= 0; i--) {
      if (data[i] == 8 || data[i] == 127) {
        backspacesCounter++;
      } else {
        if (backspacesCounter > 0) {
          backspacesCounter--;
        } else {
          buffer[--bufferIndex] = data[i];
        }
      }
    }
    print("DataString ${String.fromCharCodes(buffer)}");
    // Create message if there is new line character
    String dataString = String.fromCharCodes(buffer);

    int index = buffer.indexOf(13);
    if (~index != 0) {
      setState(() {
*//*        messages.add(
          _Message(
            1,
            backspacesCounter > 0
                ? _messageBuffer.substring(
                    0, _messageBuffer.length - backspacesCounter)
                : _messageBuffer + dataString.substring(0, index),
          ),
        );*//*
        _messageBuffer = dataString.substring(index);
      });
    } else {
      _messageBuffer = (backspacesCounter > 0
          ? _messageBuffer.substring(
              0, _messageBuffer.length - backspacesCounter)
          : _messageBuffer + dataString);
    }*/
  }

  void _sendMessage(String text) async {
    if (text.length > 0) {
      try {
        connection.output.add(utf8.encode(text + "\r\n"));
        await connection.output.allSent;
      } catch (e) {}
    }
  }

  void startConnectionToBluetooth() {
    BluetoothConnection.toAddress(server.address).then((_connection) {
      print('Connected to the device');
      connection = _connection;
      setState(() {
        isConnecting = false;
        isDisconnecting = false;
      });
      connection.input.listen(_onDataReceived).onDone(() {
        if (isDisconnecting) {
          print('Disconnecting locally!');
        } else {
          print('Disconnected remotely!');
        }
        if (this.mounted) {
          setState(() {});
        }
      });
    }).catchError((error) {
      print('Cannot connect, exception occured');
      print(error);
    });
  }
}
