window.clipboardCopy = {
    copyText: function (text) {
        navigator.clipboard.writeText(text).then(function () {
        })
            .catch(function (error) {
                console.log(error);
            });
    }
};