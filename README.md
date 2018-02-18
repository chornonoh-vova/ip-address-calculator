# ip-address-calculator
Simple calculation of network boundaries

## Usage

`ip-calculator --help` to list avalailable commands <br>
`ip-calculator --all <example-ip>/<example-prefix>` to calculate all network boundaries of given ip <br>
`ip-calculator --net <example-ip>/<example-prefix>` to calculate only network address of given ip <br>
`ip-calculator --mask <example-ip>/<example-prefix>` to show only mask <br>
`ip-calculator --broadcast <example-ip>/<example-prefix>` to calculate broadcast address

## Compile

Simply run:<br>
`cmake .`<br>
and then:<br>
`make`
