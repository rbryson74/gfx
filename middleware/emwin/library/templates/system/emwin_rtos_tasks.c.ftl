<#if HarmonyCore.SELECT_RTOS == "FreeRTOS">
    <#lt>void _EMWIN_Tasks(  void *pvParameters  )
    <#lt>{
    <#lt>    while(1)
    <#lt>    {
    <#lt>        emWin_Tasks();
             <#if rtosEnableTaskDelay >
    <#lt>        vTaskDelay(${rtosTaskDelay} / portTICK_PERIOD_MS);
             </#if>
    <#lt>    }
    <#lt>}
</#if>
