var chartRoll;

chartRoll = new Highcharts.chart({
    chart: {
	renderTo: "rollGrafica",
        type: 'spline',
        animation: Highcharts.svg,
        marginRight: 10,
    },

    time: {
        useUTC: false
    },

    title: {
        text: 'Imu Sensor'
    },

    accessibility: {
        announceNewData: {
            enabled: true,
            minAnnounceInterval: 15000,
            announcementFormatter: function (allSeries, newSeries, newPoint) {
                if (newPoint) {
                    return 'New point added. Value: ' + newPoint.y;
                }
                return false;
            }
        }
    },

    xAxis: {
        type: 'datetime',
        tickPixelInterval: 150
    },

    yAxis: [{ // Primary yAxis
        labels: {
            format: '{value}º',
            style: {
                color: Highcharts.getOptions().colors[1]
            }
        },
        title: {
            text: 'Roll',
            style: {
                color: Highcharts.getOptions().colors[1]
            }
        }
    }, { // Secondary yAxis
        title: {
            text: 'Pitch',
            style: {
                color: Highcharts.getOptions().colors[0]
            }
        },
        labels: {
            format: '{value}º',
            style: {
                color: Highcharts.getOptions().colors[0]
            }
        },
    }],

    legend: {
        layout: 'vertical',
        align: 'left',
        verticalAlign: 'top',
        floating: true,
        backgroundColor:
            Highcharts.defaultOptions.legend.backgroundColor || // theme
            'rgba(255,255,255,0.25)'
    },

    exporting: {
        enabled: false
    },

    tooltip: {
	positioner: function () {
	        return {
        		// right aligned
                	x: this.chart.chartWidth - this.label.width,
	                y: 10 // align to title
        	};
        },
        borderWidth: 0,
        backgroundColor: 'none',
        pointFormat: '{point.y}',
        headerFormat: '',
        shadow: false,
	valueSuffix: ' ' + 'º',
        style: {
        	fontSize: '18px'
        },
    },
    series: [{
        name: 'Roll',
        data: []
    },{
	name: 'Pitch',
	data: []
    }]
});

var socket = new io.connect();
socket.on('connect', function() {
	  document.getElementById("status").innerHTML="Connected";

});

socket.on('Roll', function(data) {
	var myData = parseFloat(data);
	height = myData;
	var grafica = chartRoll.series[0];
	var point = [Date.now(), height];
	if(grafica.data.length == 20) grafica.addPoint(point,true,true);
	else grafica.addPoint(point,true);
});

socket.on('Pitch', function(data) {
	var myData = parseFloat(data);
	height = myData;
	var grafica = chartRoll.series[1];
	var point = [Date.now(), height];
	if(grafica.data.length == 20) grafica.addPoint(point,true,true);
	else grafica.addPoint(point,true);
});
