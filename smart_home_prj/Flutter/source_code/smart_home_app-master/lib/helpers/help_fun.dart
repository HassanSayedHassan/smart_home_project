

import 'dart:convert';


import 'package:flutter/material.dart';
import 'package:flutter_spinkit/flutter_spinkit.dart';
import 'package:servo_app/local_data.dart';

import 'package:toast/toast.dart';




///TODO  flutter_spinkit:

class HelpFun{

static void showLoadingOrgin(context) {
   showDialog(
     context: context,
     barrierDismissible: false,
     builder: (BuildContext context) {
       return Dialog(
         child: Container(
           padding: const EdgeInsets.all(15.0),
           color: Colors.transparent,
           child: new Row(
             mainAxisAlignment: MainAxisAlignment.spaceEvenly,
             mainAxisSize: MainAxisSize.min,
             children: [
               new CircularProgressIndicator(
                 strokeWidth: 5,
                 backgroundColor: Colors.deepPurple,
               ),
               new Text("Loading..."),
             ],
           ),
         ),
       );
     },
   );
 }
static void showLoading(context) {
  showDialog(
    context: context,
    barrierDismissible: false,
    builder: (BuildContext context) {
      return SpinKitFoldingCube(

        color: textFieldColor,
        size: 50.0,
      );
    },
  );
}
static void  closeLoading(context) {

 Navigator.pop(context); //pop dialog

 }

static void showToast(context,mess){
   Toast.show(mess, context, duration: Toast.LENGTH_LONG, gravity:  Toast.CENTER,backgroundColor: Colors.blueAccent);
 }
static void showErrorToast(context,mess){
  Toast.show(mess, context, duration: Toast.LENGTH_LONG, gravity:  Toast.CENTER,backgroundColor: Colors.red);
}

static void showSuccessToast(context,mess){
  Toast.show(mess, context, duration: Toast.LENGTH_SHORT, gravity:  Toast.CENTER,backgroundColor: Colors.green);
}



}
