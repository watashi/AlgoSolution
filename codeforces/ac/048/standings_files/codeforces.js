function Codeforces() {
    this.ping = function(pingUrl) {
        Codeforces.setCookie("lastOnlineTimeUpdaterInvocation", new Date().getTime());
        $.post(pingUrl, {}, function(result) {
            for (var i = 0; i < result.length; i++) {
                alert(result[i].name + "\n----------\n\n" + result[i].text);
            }
        }, "json");
    }

    this.parseSeconds = function(seconds) {
        var ap = 0;
        if (seconds.length == 9) {
            ap = seconds.charAt(0) - '0';
            seconds = seconds.substring(1);
        }
        if (seconds.length == 8 && seconds.charAt(2) == ':' && seconds.charAt(5) == ':') {
            var s = (seconds.charAt(7) - '0') + 10 * (seconds.charAt(6) - '0');
            var m = (seconds.charAt(4) - '0') + 10 * (seconds.charAt(3) - '0');
            var h = (seconds.charAt(1) - '0') + 10 * (seconds.charAt(0) - '0') + 100 * ap;
            return s + 60 * m + 60 * 60 * h;
        } else {
            return 0;
        }
    }

    this.formatSS = function(seconds) {
        if (seconds <= 9) {
            return "0" + seconds;
        } else {
            return seconds;
        }
    }

    this.formatSeconds = function(seconds) {
        var s = seconds % 60;
        seconds = (seconds - s) / 60
        var m = seconds % 60;
        var h = (seconds - m) / 60
        return Codeforces.formatSS(h) + ":" + Codeforces.formatSS(m) + ":" + Codeforces.formatSS(s);
    }

    this.countdown = function() {
        var now = new Date().getTime();
        var e = $(".countdown");
        var starts = new Array();

        var index = 0;
        e.each(function() {
            index++;
            $(this).attr("cdid", "i" + index);
        });

        var callback = function() {
            e.each(function() {
                var textBeforeRedirect = $(this).attr("textBeforeRedirect");
                var redirectUrl = $(this).attr("redirectUrl");
                var home = $(this).attr("home");
                var noRedirection = $(this).attr("noRedirection");

                var id = $(this).attr("cdid");
                var txt = $(this).text();
                var s = Codeforces.parseSeconds(txt);
                if (s > 0) {
                    if (starts[id] == undefined)
                        starts[id] = s;
                    var passed = Math.floor((new Date().getTime() - now) / 1000);
                    var val = starts[id] - passed;
                    if (val >= 0) {
                        $(this).text(Codeforces.formatSeconds(val));
                    }
                    if (val <= 0) {
                        if (noRedirection != "true" && noRedirection != "yes") {
                            if (textBeforeRedirect) {
                                Codeforces.alert(home, textBeforeRedirect, function() {
                                        if (redirectUrl) {
                                            window.setTimeout(Codeforces.redirect(redirectUrl), Math.floor(Math.random() * 2000));
                                        } else {
                                            window.setTimeout(Codeforces.reload, Math.floor(Math.random() * 2000));
                                        }
                                });
                            } else {
                                if (redirectUrl) {
                                    window.setTimeout(Codeforces.redirect(redirectUrl), Math.floor(Math.random() * 5000));
                                } else {
                                    window.setTimeout(Codeforces.reload, Math.floor(Math.random() * 5000));
                                }
                            }
                        } else {
                            if (textBeforeRedirect)
                                Codeforces.alert(home, textBeforeRedirect);
                        }
                    }
                }
            });
            window.setTimeout(callback, 1000);
        };
        window.setTimeout(callback, 0);
    };

    this.facebox = function (target, home) {
        $("facebox").facebox(/*{
            closeImage    : (home != undefined ? home + "/" : "") + 'images/facebox/closelabel.gif',
            splitterImage : (home != undefined ? home + "/" : "") + 'images/facebox/splitter.png'
        }*/);
        $.facebox.loading(true);
        $.facebox.reveal($(target).clone().show(), null);
    }

    this.alert = function(home, html, handler) {
        var p = $("<div class='confirm-proto'><div class='text'>&nbsp;</div><div><hr/><div style='text-align:center;'><input class='ok' type='button' value='OK'/></div></div></div>").css('display', 'none');
        $(".text", p).html(html);
        if (handler) {
            $(".ok", p).click(function() {
                        handler();
                    });
        } else {
            $(".ok", p).parent().parent().css("display", "none");
        }
        $("facebox").facebox(/*{
            closeImage    : (home != undefined ? home + "/" : "") + 'images/facebox/closelabel.gif',
            splitterImage : (home != undefined ? home + "/" : "") + 'images/facebox/splitter.png'
        }*/);
        $.facebox.loading(true);
        $.facebox.reveal(p.show(), null);
    }

    this.showMessage = function(message) {
        $.jGrowl(message, {position: 'bottom-right', life: 10000});
    }

    this.focusOnError = function() {
        var found = false;

        $(".table-form .error").each(function() {
            if (!found) {
                var $this = $(this);
                var val = $.trim($this.text());
                if (val.length > 0) {
                    var classes = $this.attr("class").split(" ");
                    for (var i in classes) {
                        if (classes[i].match(/for__.*/)) {
                            var name = classes[i].substring(5);
                            found = true;
                            
                            $(".table-form input[name=" + name + "]").focus();
                            return;
                        }
                    }
                }
            }
        });

        if (!found) {
            var focusInput = null;
            $("input.focus, select.focus, textarea.focus").each(function() {
                if (!focusInput) {
                    focusInput = $(this);
                }
            });
            $(".table-form input, .table-form select, .table-form textarea").each(function() {
                if (!focusInput) {
                    var elem = $(this);
                    if ($(this).attr("type") != "hidden" && $(this).val() == "") {
                        focusInput = elem;
                    }
                }
            });
            if (focusInput) {
                focusInput.focus();
            }
        }
    }

    this.reload = function() {
        window.location.reload();
    }

    this.redirect = function(link) {
        window.location = link;
    }

    this.clearAjaxFormErrors = function(selector) {
        var form = $(selector);
        form.find("*").each(function() {
            var classes = $(this).attr("class").split(" ");
            var found = false;
            for (var i in classes)
                if (classes[i].indexOf("error__") == 0) {
                    found = true;                    
                }
            if (found) {
                $(this).find(".error").hide();
                $(this).find(".notice").show();
            }
        });
    }

    this.setAjaxFormError = function(selector, key, value) {
        $(selector).find("." + key).each(function() {
            $(".notice", this).hide();
            $(".error", this).html(value).show();
        });
    }

    this.setAjaxFormErrors = function(selector, data) {
        var result = false;
        this.clearAjaxFormErrors(selector);
        for (var i in data) {
            if (i.indexOf("error__") == 0) {
                this.setAjaxFormError(selector, i, data[i]);
                result = true;
            }
        }
        return result;
    }

    this.isEnglishText = function(s) {
        var latinLetterCount = 0; 
        for (var i = 0; i < s.length; i++) {
            var c = s.charAt(i);
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
                latinLetterCount++;
            }
        }
        return latinLetterCount > s.length / 2;
    }

    this.replaceDataForRoundTable = function(selector, titles, data, widths) {
        var rt = $(selector);
        var table = $(".rtable", rt);
        table.fadeOut(250, function() {
            var content = "";

            content += "<tr>";
            for (var j = 0; j < titles.length; j++) {
                var attr = "";
                if (j == 0)
                     attr += " class=\"left\"";
                if (widths != undefined && widths[j] != undefined)
                     attr += " style=\"width:" + widths[j] + ";\"";
                content += "<th" + attr + ">";
                content += titles[j] + "</th>";
            }
            content += "</tr>";

            for (var i = 0; i < data.length; i++) {
                var row = data[i];
                content += "<tr>";
                for (var j = 0; j < row.length; j++) {
                    var clazz = "";
                    if (j == 0)
                        clazz += "left ";
                    if (i + 1 == data.length)
                        clazz += "bottom ";
                    if (i % 2 == 0)
                        clazz += "dark ";
                    content += "<td class=\"" + clazz + "\">" + row[j] + "</td>";
                }
                content += "</tr>";
            }
            table.html(content);
            table.fadeIn(250);
        });
    }

    /*
    this.changeRowIndex = function(selector, from, to) {
        if (from != to) {
            var init = $(selector + " tr:nth-child(" + from + ")");
            var target = $(selector + " tr:nth-child(" + to + ")");
            var duration = 250 + 50 * Math.abs(from - to);
            if (init != undefined && target != undefined) {
                var tr = init.clone();
                $(selector).append(tr);
                tr.css("display", "block").css("position", "absolute")
                        .css("top", init.position().top).css("background", "#FFF7DB !important")
                        .css("border", "3px solid #e1e1e1").css("font-size", "1.25em")
                        .css("left", (target.position().left-10) + "px");
                tr.find("td").css("background", "#FFF7DB !important");
                tr.show();
                init.animate({
                    opacity: "hide"
                }, {
                    queue: false,
                    duration: duration
                });
                tr.animate({
                    "top": target.position().top
                }, duration, function() {
                    tr.hide();
                    init.detach();
                    init.show();
                    if (from > to)
                        target.before(init);
                    else
                        target.after(init);
                    $(".datatable").each(function() {
                        $(this).find("td").removeClass("bottom").removeClass("dark");
                        $(this).find("tr:first th").addClass("top");
                        $(this).find("tr:last td").addClass("bottom");
                        $(this).find("tr:odd td").addClass("dark");
                        $(this).find("tr td:first-child, tr th:first-child").addClass("left");
                        $(this).find("tr td:last-child, tr th:last-child").addClass("right");
                    });
                });
            }
        }
    }
    */

    this.parentForm = function(elem) {
        while(elem && elem.tagName != "FORM") {
            elem = elem.parentNode;
        }
        return elem;
    }

    this.setCookie = function(name, value) {
        document.cookie = name + "=" + escape(value);
    };

    this.getCookie = function(name) {
        var prefix = name + "=";
        var from = document.cookie.indexOf(prefix);
        if (from < 0) {
                return null;
        } else {
            var to = document.cookie.indexOf(";", from + prefix.length);
            if (to < 0) {
                    to = document.cookie.length;
            }
            return unescape(document.cookie.substring(from + prefix.length, to));
        }
    };
}

Codeforces = new Codeforces();
