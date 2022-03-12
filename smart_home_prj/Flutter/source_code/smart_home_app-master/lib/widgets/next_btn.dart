import 'package:flutter/material.dart';
import 'package:flutter_screenutil/flutter_screenutil.dart';
import 'package:servo_app/local_data.dart';
Widget drawNextBtn({
  Function onTap,
}) {
  return InkWell(
    onTap: onTap,
    child: Container(
      margin: EdgeInsets.symmetric(horizontal: 600.w),
      width: double.infinity,
      height: 200.h,
      decoration: BoxDecoration(
        color: textFieldColor,
        borderRadius: BorderRadius.all(
          Radius.circular(10),
        ),
        border: Border.all(
          width: 1,
          color: textFieldColor,
          style: BorderStyle.solid,
        ),
        boxShadow: [
          BoxShadow(blurRadius: 1, color: textFieldColor, spreadRadius: 1)
        ],
      ),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Text(
            "log  in",
            textAlign: TextAlign.center,
            style: TextStyle(
              fontSize: 120.sp,
              fontWeight: FontWeight.bold,
              color: Color(0xff3A3737),
            ),
          ),
        ],
      ),
    ),
  );
}