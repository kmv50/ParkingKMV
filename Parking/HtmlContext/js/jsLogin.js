$(document).ready(function () {
    $('#b_logiar').click(function () {
//        new QWebChannel(qt.webChannelTransport, function (channel) {
//             channel.objects.qt.LoginAction({
//                'user': $('#txt_usuario').val(),
//                'password': $('#txt_password').val()
//            }, function (json) {
//                alert(json['State']);
//            });
//        });

        new QWebChannel(qt.webChannelTransport, function (channel) {
             channel.objects.qt.LoginAction({
                'user': $('#txt_usuario').val(),
                'password': $('#txt_password').val()
            });
        });
    });
});
