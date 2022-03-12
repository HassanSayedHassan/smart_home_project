import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter_screenutil/flutter_screenutil.dart';
import 'package:servo_app/helpers/help_fun.dart';
import 'package:servo_app/local_data.dart';
import 'package:servo_app/pages/Home_page.dart';
import 'package:servo_app/widgets/next_btn.dart';
import '../res.dart';

class LogInPage extends StatefulWidget {


  @override
  _LogInPageState createState() => _LogInPageState();
}

class _LogInPageState extends State<LogInPage> {

  TextEditingController nameController=TextEditingController(text: "");
  TextEditingController passController=TextEditingController(text: "");

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        body: SingleChildScrollView(
          child: Column(
            children: [
              Stack(
                children: [
                  Container(
                    width: 2005.w,
                    height: 3564.h,
                    child: Image.asset(
                      Res.back_ground,
                      fit: BoxFit.cover,
                    ),
                  ),
                Column(
                  children: [
                  SizedBox(
                    height: 330.h,
                  ),
                   Row(
                     mainAxisAlignment: MainAxisAlignment.center,
                     children: [
                       InkWell(
                         onTap: ()
                         {

                         }
                         ,child: Container(
                           height: 890.h,
                           width: 890.w,
                           child: Image.asset(Res.logo,
                             fit: BoxFit.fitWidth,
                           ),
                         ),
                       ),
                     ],
                   ) ,
                    Text("log in system",style: TextStyle(
                      color: Colors.white.withOpacity(0.6),
                      fontSize: 130.sp,
                    ),
                      ),
                    SizedBox(
                      height: 350.h,
                    ),

                    drawGroupsTextField(controller: nameController,hintText: "Enter your Name"),
                    SizedBox(
                      height: 130.h,
                    ),
                    drawGroupsTextField(controller: passController ,hintText: "Enter your Password"),
                    SizedBox(
                      height: 130.h,
                    ),
                    drawNextBtn(onTap: ()
                    {
                      chcekUser();
                    })
                  ],
                ),
                  Positioned(
                    bottom: 370.h,
                    left: 620.w,
                   //   alignment: Alignment.bottomCenter,
                      child: Row(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Container(
                            alignment: Alignment.center,
                         //   padding: EdgeInsets.all(160.h),
                            child: Text(
                              "Made    By :     M-H-M",
                              style: TextStyle(
                                  color: textFieldColor,
                                  fontSize: 100.sp),
                            ),
                          ),
                        ],
                      )),

                ],
              ),
            ],
          ),
        ),
      ),
    );
  }

  Widget drawGroupsTextField(
      {TextEditingController controller,
        String hintText,
        String Function(String val) validate}) {
    return Container(
      padding: EdgeInsets.symmetric(horizontal: 400.w),
      alignment: Alignment.center,
      child: TextFormField(
        controller: controller,
        validator: validate,
        textAlign: TextAlign.center,
        decoration: InputDecoration(
          enabledBorder: OutlineInputBorder(
            borderSide: BorderSide(color: textFieldBorderColor, width: 2),
            borderRadius: BorderRadius.circular(300.sp),
          ),
          focusedBorder: OutlineInputBorder(
            borderSide: BorderSide(color: textFieldBorderColor, width: 2),
            borderRadius: BorderRadius.circular(300.sp),
          ),
          contentPadding: EdgeInsets.all(5),
          filled: true,
          hintText: hintText,
          hintStyle: TextStyle(
            color: Colors.black,
            fontSize: 100.sp,
          ),
          fillColor: textFieldColor,
        ),
        style: TextStyle(
          color: Colors.black,
          fontSize: 100.sp,
        ),
      ),
    );
  }

  void chcekUser()
  {
    HelpFun.showLoading(context);
    int status=0;
    for (int i=0;i<savedUsers.length;i++)
      {
        if(savedUsers[i].userName==nameController.text && savedUsers[i].userPass==passController.text)
        {
          status=1;
          HelpFun.closeLoading(context);
          Navigator.push(context, MaterialPageRoute(builder: (context) => HomePage(savedUsers[i]),));
        }
      }
    if(status==0)
      {
        HelpFun.closeLoading(context);
        HelpFun.showErrorToast(context, "Not Correct user");
      }

  }
}
