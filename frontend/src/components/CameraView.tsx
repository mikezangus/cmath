import React, { useEffect, useState, useRef } from "react";
import { StyleSheet, Text, View } from "react-native";
import { Camera, useCameraDevices } from "react-native-vision-camera";


export default function CameraView() {
    const [hasPermission, setHasPermission] = useState<boolean | null>(null);
    const devices = useCameraDevices();
    const device = devices.find((d) => d.position === "back");
    const camera = useRef<Camera | null>(null);

    useEffect(() => {
        (async () => {
            const status = await Camera.requestCameraPermission();
            setHasPermission(status === "granted");
        })();
    }, []);

    if (hasPermission === null) {
        return (
            <Text>
                Requesting permission...
            </Text>
        );
    }
    if (hasPermission === false) {
        return (
            <Text>
                No access to camera
            </Text>
        );
    }
    if (device == null) {
        return (
            <Text>
                Loading camera...
            </Text>
        );
    }

    return (
        <Camera
            ref={camera}
            style={StyleSheet.absoluteFill}
            device={device}
            isActive={true}
        />
    );
}
